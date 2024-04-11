#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
const int N=200050;
const int inf=1e9+7;
char s[N];
int dp[N][2][2][2][2];//0 L, 1 R
int main(){
	for(int t=ri();t--;){
		int n=ri();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			for(int t=0;t<16;t++)
				dp[i][t&1][t>>1&1][t>>2&1][t>>3&1]=inf;
		dp[2][0][1][0][1]=(int)(s[1]!='L')+(s[2]!='L');
		dp[2][0][0][1][0]=(int)(s[1]!='L')+(s[2]!='R');
		dp[2][1][0][0][0]=(int)(s[1]!='R')+(s[2]!='L');
		dp[2][1][1][1][1]=(int)(s[1]!='R')+(s[2]!='R');
		auto get=[&](char c,int l){
			if(l==0)return c!='L';
			else return c!='R';
		};
		for(int i=2;i<n;i++){
			for(int fir=0;fir<2;fir++){
				for(int fsz=0;fsz<2;fsz++){
					for(int las=0;las<2;las++){
						for(int lsz=0;lsz<2;lsz++){
							if(lsz==0)ckmn(dp[i+1][fir][fsz][las][lsz+1],dp[i][fir][fsz][las][lsz]+get(s[i+1],las));
							ckmn(dp[i+1][fir][fsz][las^1][0],dp[i][fir][fsz][las][lsz]+get(s[i+1],las^1));
						}
					}
				}
			}
		}
		int ans=inf;
		for(int fir=0;fir<2;fir++){
			for(int fsz=0;fsz<2;fsz++){
				for(int las=0;las<2;las++){
					for(int lsz=0;lsz<2;lsz++){
						if(fir!=las||fsz+lsz==0)ckmn(ans,dp[n][fir][fsz][las][lsz]);
					}
				}
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}