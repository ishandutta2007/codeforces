#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,a[100010],dp[2][2][210],su1[210],su2[210];
int mod = 998244353;
inline int sq(int x){return 1ll*x*x%mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int pow(int a,int b){if(b == 0)return 1;return b&1?mul(sq(pow(a,b/2)),a):sq(pow(a,b/2));}
inline int inv(int a){return pow(a,mod-2);}
int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	int cc = 0;
	for(int ech=1;ech<=n;ech++){
		set0(dp[cc^1]);
		set0(su1);set0(su2);
		int csu = 0;
		if(ech == 1)csu = 1;
		for(int i=1;i<=200;i++){
			if(i == a[ech] || a[ech] == -1){
				dp[cc^1][0][i]=add(dp[cc^1][0][i],csu);
				dp[cc^1][1][i]=add(dp[cc^1][1][i],dp[cc][0][i]);
			}
			csu=add(csu,dp[cc][0][i]);
			csu=add(csu,dp[cc][1][i]);
		}
		csu = 0;
		for(int i=200;i>=1;i--){
			csu=add(csu,dp[cc][1][i]);
			if(i == a[ech] || a[ech] == -1)dp[cc^1][1][i]=add(dp[cc^1][1][i],csu);
		}
		cc^=1;
	}
	int ans = 0;
	for(int i=200;i>=1;i--)ans = add(ans,dp[cc][1][i]);
	cout<<ans<<endl;
	return 0;
}