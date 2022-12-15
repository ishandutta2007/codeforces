#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
// const ll mod = 998244353;
typedef pair<double,double> pdd;
const int mn = 1e6+10;
const int SZ = 700;
const double pi = acos(-1.);
mt19937 rng(time(0));

vi g[mn];
int dp[mn],h[mn];
void dfs(int x){
	h[x]=1;
	for(int y:g[x]){
		dfs(y);
		h[x]=max(h[x],h[y]+1);
	}
	int s=0;
	for(int y:g[x]){
		s+=dp[y];
	}
	dp[x]=max(h[x],s);
}
void solve() {
	int n;
	cin >> n;
	for(int i=2;i<=n;i++){
		int a;
		cin >> a;
		g[a].push_back(i);
	}
	dfs(1);
	printf("%d\n",dp[1]);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
	int tc=1;
	// cin >> tc;
	for(int tcc=1;tcc<=tc;tcc++){
		//printf("Case #%d: ",tcc);
		solve();
	}
}