#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi g[1001];
bool ans = false;
bool vis[1001];
void dfs(int st){
	vis[st] = true;
	if(!g[st].empty()){
		int cnt = 0;
		trav(i,g[st]){
			if(g[i].empty()) cnt++;
			dfs(i);
		}
		if(cnt<3) ans = true;
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;	
	rep(i,n-1){
		int x;cin>>x;
		g[x].pb(i+2);
	}
	repA(i,1,n){
		if(!vis[i]) dfs(i);
	}
	if(!ans) cout<<"Yes";
	else cout<<"No";
	return 0;
}