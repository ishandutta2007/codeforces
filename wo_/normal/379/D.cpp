#include<cstdio>
#include<string>

using namespace std;

struct Str{
	char le,ri;
	long long num;
	Str(){}
	Str(char l,char r,long long n){
		le=l,ri=r,num=n;
	}
};

Str add(Str s1,Str s2){
	Str res;
	res.le=s1.le;
	res.ri=s2.ri;
	res.num=s1.num+s2.num;
	if(s1.ri=='A'&&s2.le=='C') res.num++;
	if(res.num>1e9){
		res.num=(1e9+10);
	}
	return res;
}

string get(Str s,int ln){
	string res;
	res+=s.le;
	for(int i=0;i<s.num;i++){
		if(i==0&&res.back()=='A'){
			res+="C";
		}else{
			res+="AC";
		}
	}
	if(res.back()!=s.ri){
		res+=s.ri;
	}
	if(res.size()>ln) return "";
	int a=ln-res.size();
	string tmp;
	for(int i=0;i<a;i++) tmp+="B";
	res=res.substr(0,res.size()-1)+tmp+res.back();
	return res;
}

int K,X,N,M;

bool simulate(Str s1,Str s2){
	Str ss[55];
	ss[1]=s1;
	ss[2]=s2;
	for(int i=3;i<=K;i++){
		ss[i]=add(ss[i-2],ss[i-1]);
	}
	return ss[K].num==X;
}

string ans1,ans2;

void solve(){
	for(int i=0;i<=N/2;i++) for(int j=0;j<=M/2;j++){
		for(char ch1='A';ch1<='C';ch1++) for(char ch2='A';ch2<='C';ch2++){
			for(char ch3='A';ch3<='C';ch3++) for(char ch4='A';ch4<='C';ch4++){
				Str s1(ch1,ch2,i);
				Str s2(ch3,ch4,j);
				bool flg=simulate(s1,s2);
				if(flg){
					ans1=get(s1,N);
					ans2=get(s2,M);
					if(ans1==""||ans2=="") continue;
					else return;
				}
			}
		}
	}
	ans1="";
	ans2="";
}

int main(){
	scanf("%d%d%d%d",&K,&X,&N,&M);
	solve();
	if(ans1==""){
		printf("Happy new year!\n");
	}else{
		printf("%s\n%s\n",ans1.c_str(),ans2.c_str());
	}
	return 0;
}