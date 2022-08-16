/*input
6 6 3
2 2 6
1 4 5
2 3 4
1 4 1
1 3 1
2 2 3
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

#define MX 300005

int n,m,s;
struct node{
	int ind,t,u,v;
	bool rev = false;
};

vector<node> edg;
vector<pii> adj[MX];
bitset<MX> vis;
int cnt = 0;

void dfs1(int s){
	vis[s] = 1;
	cnt ++;
	for(auto x:adj[s]){
		if(vis[x.F]) continue;
		if(edg[x.S].t == 1){
			dfs1(x.F);
			continue;
		}
		if(edg[x.S].u == x.F) edg[x.S].rev = true;
		dfs1(x.F);
	}
}


void dfs2(int s){
	vis[s] = 1;
	cnt ++;
	for(auto x:adj[s]){
		if(vis[x.F]) continue;
		if(edg[x.S].t == 1){
			dfs2(x.F);
			continue;
		}
		if(edg[x.S].u != x.F) edg[x.S].rev = true;
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> s;
	REP(i,m){
		node x;
		cin >> x.t >> x.u >> x.v;
		x.ind = i;
		edg.pb(x);
		adj[x.u].pb({x.v,i});
		if(x.t == 2) adj[x.v].pb({x.u,i});
	}
	dfs1(s);
	cout << cnt << endl;
	REP(i,m){
		if(edg[i].t == 2){
			if(edg[i].rev) cout << "-";
			else cout << "+";
			edg[i].rev = false;
		}
	}
	cout << "\n";


	vis = 0;
	cnt = 0;
	dfs2(s);
	cout << cnt << endl;
	REP(i,m){
		if(edg[i].t == 2){
			if(edg[i].rev) cout << "-";
			else cout << "+";
		}
	}
	cout << "\n";
}