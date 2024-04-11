#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,dt[20];
LL pw[20];
char s[20];
int to_int(int c){
	if(isdigit(c))return c-'0';
	return c-'a'+10;
}
char to_char(int c){
	if(c<=9)return c+'0';
	else return c-10+'a';
}
int main(){
	pw[0]=1;
	rep(i,1,14)pw[i]=pw[i-1]*16LL;
	scanf("%s",s);
	LL a=0;
	n=strlen(s);
	reverse(s,s+n);
	int pop_s=0;
	per(i,n-1,0)a=a*16+to_int(s[i]),pop_s+=to_int(s[i]);
	if(pop_s%15!=0)puts("NO"),exit(0);
	int jw=pop_s/15;
	LL ans=INFLL;
	rep(mask,0,(1<<n)-1)if((~mask>>(n-1)&1)&&__builtin_popcount(mask)==jw){
		DD(mask);
		rep(i,0,n-1){
			dt[i]=to_int(s[i]);
		}
		rep(i,0,n-1)if(mask>>i&1){
			dt[i+1]+=1;
			dt[i]-=16;
		}
		
		vector<LL>dp(1<<(n-1),INFLL);
		dp[0]=0;
		vector<int>sum(1<<(n-1));
		sum[0]=dt[n-1];
		rep(i,1,(1<<(n-1))-1)sum[i]=sum[i&(i-1)]+dt[__builtin_ctz(i)];
		
		rep(i,0,(1<<(n-1))-1){
			DD(mask,i);
			if(sum[i]<0||sum[i]>=16)continue;
			rep(j,0,n-2)if(~i>>j&1)dp[i^(1<<j)]=min(dp[i^(1<<j)],dp[i]+(sum[i]*pw[j]));
		}
		ans=min(ans,dp[(1<<(n-1))-1]);
	}
	if(ans==INFLL)puts("NO");else{
		vector<int>v;
		rep(i,0,n-1)v.pb(ans%16),ans/=16;
		per(i,SZ(v)-1,0)printf("%c",to_char(v[i]));
		puts("");
	}
	return 0;
}