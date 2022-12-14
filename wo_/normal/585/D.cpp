#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,string> PIS;

const int inf=1e9;

//map<PII,PIS> mp1,mp2;
map<PII,PII> mp1,mp2;

int N;
int ls[25],ms[25],ws[25];

//void dfs(map<PII,PIS> &mp,int *ls,int *ms,int *ws,int ln,int l,int m,int w,int id,string str){
void dfs(map<PII,PII> &mp,int *ls,int *ms,int *ws,int ln,int l,int m,int w,int id,int mask){
	if(id==ln){
		PII key=PII(l-m,l-w);
//		PIS val=PIS(l,str);
		PII val=PII(l,mask);
		if(mp.count(key)==0||mp[key]<val){
			mp[key]=val;
		}
		return;
	}
	
//	str+="L";
//	m+=ms[id];
//	w+=ws[id];
	dfs(mp,ls,ms,ws,ln,l,m+ms[id],w+ws[id],id+1,mask*3+0);
//	str=str.substr(0,str.size()-1);
//	m-=ms[id];
//	w-=ws[id];
	
//	str+="M";
//	l+=ls[id];
//	w+=ws[id];
	dfs(mp,ls,ms,ws,ln,l+ls[id],m,w+ws[id],id+1,mask*3+1);
//	str=str.substr(0,str.size()-1);
//	l-=ls[id];
//	w-=ws[id];
	
//	str+="W";
//	l+=ls[id];
//	m+=ms[id];
	dfs(mp,ls,ms,ws,ln,l+ls[id],m+ms[id],w,id+1,mask*3+2);
//	str=str.substr(0,str.size()-1);
//	l-=ls[id];
//	m-=ms[id];
}

void solve1(){
	if(ls[0]==0&&ms[0]==0){
		printf("LM\n");
	}else if(ls[0]==0&&ws[0]==0){
		printf("LW\n");
	}else if(ms[0]==0&&ws[0]==0){
		printf("MW\n");
	}else{
		printf("Impossible\n");
	}
}

string decode(long long mask,int ln){
	string res="";
	for(int i=0;i<ln;i++){
		if(mask%3==0){
			res+="L";
		}else if(mask%3==1){
			res+="M";
		}else{
			res+="W";
		}
		mask/=3;
	}
	reverse(res.begin(),res.end());
	return res;
}

void solve(){
	if(N==1){
		solve1();
		return;
	}
	dfs(mp1,ls,ms,ws,N/2,0,0,0,0,0);
	dfs(mp2,ls+N/2,ms+N/2,ws+N/2,N-N/2,0,0,0,0,0);
	//map<PII,PIS>::iterator it=mp1.begin();
	map<PII,PII>::iterator it=mp1.begin();
	int Ma=-inf;
	long long mask=0;
	int coe=1;
	for(int i=0;i<(N-N/2);i++) coe*=3;
	string res="";
	for(;it!=mp1.end();it++){
		PII key=it->first;
		//PIS value=it->second;
		PII value=it->second;
		PII nkey=PII(-key.first,-key.second);
		if(mp2.count(nkey)>=1){
		//	PIS value2=mp2[nkey];
			PII value2=mp2[nkey];
			if(Ma<value.first+value2.first){
				Ma=value.first+value2.first;
				//res=value.second+value2.second;
				mask=(long long)value.second*coe+value2.second;
			}
		}
	}
	res=decode(mask,N);
	if(Ma!=-inf){
		for(int i=0;i<res.size();i++){
			if(res[i]=='L'){
				printf("MW\n");
			}else if(res[i]=='M'){
				printf("LW\n");
			}else{
				printf("LM\n");
			}
		}
	}else{
		printf("Impossible\n");
	}
}

void input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",ls+i,ms+i,ws+i);
	}
}

int main(){
	input();
	solve();
	return 0;
}