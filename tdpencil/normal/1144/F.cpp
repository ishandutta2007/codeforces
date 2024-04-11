#include <bits/stdc++.h>
const int INF = 1000000000;
using namespace std;

using ll = long long;
#define vt vector
#define all(x) x.begin(),x.end()
#define ull unsigned ll
#define sz(x) (int(x.size()))
#define vi vector<int>
#define pb push_back
#define vl vector<ll>
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vpi vt<pi>
#define vpl vt<pl>
#define vvi vt<vi>
#define vvvi vt<vvi>
#define ar array

int n, k;

const int MAXN = 2e5+1;
int a[MAXN];
vi adj[MAXN];
bool vis[MAXN];
int clr[MAXN];
vi qu;
bool dfs(int c, int r=0) {
	clr[c]=r;
	for(int e : adj[c]) {
		if(clr[e] == -1) {
			if(!dfs(e, r^1))
				return 0;
		} else {
			if(clr[e]==clr[c])
				return 0;
		}
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);	
	cin >> n >> k;
	fill(clr, clr + n, -1);
	for(int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
		qu.pb(x);
		qu.pb(y);
	}
	if(dfs(0)) {
		cout << "YES\n";
		string ans;
		for(;qu.size();) {
			int x=qu.back();
			qu.pop_back();
			int y=qu.back();
			qu.pop_back();
			if(clr[x]==0)
				ans+='0';
			else
				ans+='1';
		}
		reverse(all(ans));
		cout << ans;
	} else {
		cout << "NO\n";
	}
}