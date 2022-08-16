/*input
6 2 3
1 2
1 5
2 3
3 4
4 5
5 6
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,m,d;
int mark[100005];
vi adj[100005];
int in[100005],out[100005];

void dfs1(int s,int p){
	if(!mark[s]) in[s] = -INF;
	for(auto x:adj[s]){
		if(x==p) continue;
		dfs1(x,s);
		remax(in[s],1+in[x]);
	}
}

void dfs2(int s,int p){
	int mx1 = -INF,mx2 = -INF;
	for(auto x:adj[s]){
		if(x==p) continue;
		if(in[x] > mx1) mx2 = mx1,mx1 = in[x];
		else if(in[x] > mx2) mx2 = in[x];
	}
	for(auto x:adj[s]){
		if(x==p) continue;
		int use = (in[x]==mx1)?mx2:mx1;
		out[x] = max(use+2,out[s]+1);
		if(mark[x]) remax(out[x],(ll)0);
		dfs2(x,s);
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> d;
	REP(i,m){
		int x;cin >> x;
		mark[x] = 1;
	}
	REP(i,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1,-1);
	if(!mark[1]) out[1] = -INF;
	dfs2(1,-1);
	int ans = 0;
	FOR(i,1,n+1){
		if(max(in[i],out[i]) <= d) ans++;
	}
	cout << ans;
}