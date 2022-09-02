#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=2005;
int T,n,dp1[N][N*2],dp2[N][N*2];
char s[N],t[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>(s+1)>>(t+1);
		for(int i=1;i<=n;i+=2){
			if(s[i]>='0'&&s[i]<='1')s[i]^=1;
			if(t[i]>='0'&&t[i]<='1')t[i]^=1;
		}
		dp1[0][0+N]=1;
		rep(i,1,n){
			memset(dp1[i],0,sizeof(dp1[i]));
			rep(x,0,1)if(s[i]==x+'0'||s[i]=='?'){
				rep(y,0,1)if(t[i]==y+'0'||t[i]=='?'){
					rep(j,-n,n){
						uad(dp1[i][j+x-y+N],dp1[i-1][j+N]);
					}
				}
			}
		}
		memset(dp2[n+1],0,sizeof(dp2[n+1]));
		dp2[n+1][0+N]=1;
		per(i,n,1){
			memset(dp2[i],0,sizeof(dp2[i]));
			rep(x,0,1)if(s[i]==x+'0'||s[i]=='?'){
				rep(y,0,1)if(t[i]==y+'0'||t[i]=='?'){
					rep(j,-n,n){
						uad(dp2[i][j+x-y+N],dp2[i+1][j+N]);
					}
				}
			}
		}
		int ans=0;
		rep(i,1,n-1){
			rep(j,-n,n){
				uad(ans,mu(abs(j),dp1[i][j+N],dp2[i+1][-j+N]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}