#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb push_back
#define AA first
#define BB second
#define ONES(x) __builtin_popcount(x)
#define _  << "  " <<
using namespace std;

typedef pair<int, int> P;
typedef long long ll ;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const double eps =1e-8;
const int mod = 1000000007;
const double PI = acos(-1.0);
inline int read(){ int num;    scanf("%d",&num);   return num;}
const int maxn = 1000007;

int a[maxn];
int b[maxn];
int pos[maxn];//

vector<ll> dp[maxn];//dp[i][j]  ji
map<int,int> id;
ll ans;

int main()
{
	ll n,k,l;
	cin>>n>>l>>k;
	for(int i = 0; i<n; i++){
		a[i] = read();
		b[i] = a[i];
	}
	sort(b,b+n);
	for(int i = 0; i<n; i++)	id[b[i]] = i;	//
	ll m = min(l/n,k);
	int res = l%n;
	for(int i = 0; i<n; i++){
		dp[1].pb(1);
		pos[i] = id[b[i]];
	}

	for(int i = 2; i<=m+1; i++){	//dpm+1
		ll s = 0;	int x = 0;
		for(int j = 0; j<n; j++){
			while(x<=pos[j])	s = (s + dp[i-1][x++])%mod;
			dp[i].pb(s);
		}
	}

	for(int i = 1; i<=m; i++)
		for(int j = 0; j<n; j++)
			ans = (ans + dp[i][j] * ((l/n-i+1)%mod) )%mod; //

	for(int i = 0; i<res; i++){					//
		int o = id[a[i]];
		for(int j = 1; j<=min(k,l/n+1); j++){	//
			ans = (ans + dp[j][o])%mod;
		}
	}
	cout << ans << endl;
    return 0;
}