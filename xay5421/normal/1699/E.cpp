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
const int N=1000005,M=5000005,INF=0X3F3F3F3F;
int T,n,m,a[N],bin[M],tot[M],dp[M];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,m)bin[i]=0,tot[i]=0,dp[i]=INF;
		rep(i,1,n){
			rd(a[i]);
			bin[a[i]]=1;
			tot[a[i]]=1;
		}
		int mn=*min_element(a+1,a+n+1);
		int mx=m;
		int ans=m;
		per(i,m,1){
			dp[i]=i;
			if(i<=m/i)for(int j=i*i;j<=m;j+=i){
				if(bin[j]){
					--tot[dp[j]];
				}
				dp[j]=min(dp[j],dp[j/i]);
				if(bin[j]){
					++tot[dp[j]];
				}
			}
			while(!tot[mx])--mx;
			ans=min(ans,mx-min(mn,i));
		}
		printf("%d\n",ans);
	}
	return 0;
}