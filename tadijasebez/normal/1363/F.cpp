#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=2050;
const int inf=1e9+7;
char s[N],t[N];
int c_s[26][N],c_t[26][N];
int main(){
	for(int tc=ri();tc--;){
		int n=ri();
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=0;i<26;i++)c_s[i][n+1]=c_t[i][n+1]=0;
		for(int i=n;i>=1;i--){
			for(int j=0;j<26;j++)c_s[j][i]=c_s[j][i+1],c_t[j][i]=c_t[j][i+1];
			c_s[s[i]-'a'][i]++;
			c_t[t[i]-'a'][i]++;
		}
		vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
		dp[n][n]=0;
		for(int i=n;i>=0;i--){
			for(int j=n;j>=0;j--){
				if(i&&j&&s[i]==t[j])ckmn(dp[i-1][j-1],dp[i][j]);
				if(i)ckmn(dp[i-1][j],dp[i][j]+1);
				if(j){
					int now=t[j]-'a';
					if(c_s[now][i+1]>c_t[now][j+1])ckmn(dp[i][j-1],dp[i][j]);
				}
			}
		}
		if(dp[0][0]==inf)printf("-1\n");
		else printf("%i\n",dp[0][0]);
	}
	return 0;
}