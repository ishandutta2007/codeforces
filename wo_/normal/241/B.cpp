#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

typedef pair<long long,long long> P;

const int D=30;

int N,M;
int a[50050];

P calc2(vector<int> &v1,vector<int> &v2){
	P res;
	res.first=(long long)(v1.size())*v2.size();
	res.second=0;
	long long c1[30],c2[30];
	for(int i=0;i<30;i++){
		c1[i]=0;
		c2[i]=0;
	}
	for(int i=0;i<v1.size();i++){
		int val=v1[i];
		for(int j=0;j<30;j++){
			if((val>>j)&1){
				c1[j]++;
			}
		}
	}
	for(int i=0;i<v2.size();i++){
		int val=v2[i];
		for(int j=0;j<30;j++){
			if((val>>j)&1){
				c2[j]++;
			}
		}
	}
	for(int i=0;i<30;i++){
		long long num=c1[i]*(v2.size()-c2[i])+c2[i]*(v1.size()-c1[i]);
		num%=mod;
		int c=1<<i;
		res.second+=num*c;
		res.second%=mod;
	}
	return res;
}

map<int,vector<int> > mp;

P calc(int pref,int d){
	mp.clear();
	for(int i=0;i<N;i++){
		int cur=(a[i]>>(D-d));
		mp[cur].push_back(a[i]);
	}
	map<int,vector<int> > :: iterator it=mp.begin();
	P res=P(0,0);
	for(;it!=mp.end();it++){
		int cur=it->first;
		int other=cur^pref;
		if(other<cur) continue;
		if(mp.count(other)==0) continue;
		P p=calc2(mp[cur],mp[other]);
//		printf("(%d,%d)\n",cur,other);
		if(cur==other){
			if(p.second%2==0) p.second/=2;
			else p.second=(p.second+mod)/2;
			long long n=mp[cur].size();
			p.first=n*(n+1)/2;
		}
		res.first+=p.first;
		res.second+=p.second;
	}
	return res;
}

string to_bin(int num){
	string str;
	while(num>0){
		int b=num&1;
		char ch='0'+b;
		str=ch+str;
		num/=2;
	}
	return str;
}

long long solve(){
	int cur_pref=0;
	int cur_dig=1;
	P res=P(0,0);
	while(cur_dig<=D){
		P cur=calc(cur_pref,cur_dig);
		string str=to_bin(cur_pref);
		int x=cur_dig-str.size();
		for(int i=0;i<x;i++) str='0'+str;
//		if(res.first+cur.first>M){
//			cur_dig++;
//			cur_pref<<=1;
//			continue;
//		}
		if(res.first+cur.first<=M){
			res.first+=cur.first;
			res.second=(res.second+cur.second)%mod;
			cur_pref++;
		}
		cur_dig++;
		if(cur_dig<=30) cur_pref<<=1;
	}
	P p=calc(cur_pref,30);
	long long num=min(p.first,M-res.first);
	res.second+=num*cur_pref;
	res.second%=mod;
	return res.second;
}

long long calc_all(){
	long long c[30];
	for(int i=0;i<30;i++){
		c[i]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<30;j++){
			if((a[i]>>j)&1){
				c[j]++;
			}
		}
	}
	long long res=0;
	for(int i=0;i<30;i++){
		long long num=c[i]*(N-c[i]);
		num%=mod;
		int x=1<<i;
		res+=num*x;
		res%=mod;
	}
	return res;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	M=(long long)N*(N+1)/2-M;
	long long num=solve();
	long long all=calc_all();
	long long ans=all-num;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}