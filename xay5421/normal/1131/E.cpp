#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
#define int long long 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void read(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;} 
template<typename T>void print(T x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10+48);}
template<typename T>void print(T x,int ch){print(x),putchar(ch);}
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
const int INF=1000000000;
int nn,ans,cur,nxt;std::string s[100005];
int fpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=a*a){
		if(a>=INF)return INF;
		if(a&1)res=res*a;
		if(res>=INF)return INF;
	}
	return res;
}
signed main(){
	read(nn);
	rep(_,1,nn)std::cin>>s[_];
	rep(t,'a','z'){
		cur=0;
		rep(_,1,nn){
			int tmp=0,res=0;
			for(int i=0;i<s[_].size();++i)if(s[_][i]==t)++tmp,res=max(res,tmp);else tmp=0;
			if(res==s[_].size())cur=min(1000000000ll,(int)(cur*(s[_].size()+1)+(int)s[_].size()));
			else{
				int ret=0;
				for(int i=0;i<s[_].size();++i)if(s[_][i]==t)++ret;else break;
				for(int i=(int)s[_].size()-1;i>=0;--i)if(s[_][i]==t)++ret;else break;
				if(cur>0)cur=ret+1;
				else cur=0;
				cur=min(max(cur,res),1000000000ll);
			}
		}
		ans=max(ans,cur);
	}
	print(ans,'\n');
	return 0;
}