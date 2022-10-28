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
typedef pair<ll, ll> pii;
typedef vector<int> vi;
ll a[200009];
bool vis[200009];
vector<pii> g[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,m,u,v,w;cin>>n>>m;
	rep(i,m) {cin>>u>>v>>w;u--,v--,w*=2;g[u].pb(mp(v,w));g[v].pb(mp(u,w));}
	priority_queue<pii> q;
	rep(i,n) {
		cin>>a[i];q.push(mp(-a[i],i));
	}
	while(!q.empty()){
		pii z = q.top();
		q.pop();
		z.fst*=-1;
		if(vis[z.snd]) continue;
		vis[z.snd]=true;
		trav(i,g[z.snd]){
			if(a[i.fst]>a[z.snd]+i.snd){
				a[i.fst] =a[z.snd]+i.snd;
				q.push(mp(-a[i.fst],i.fst));
			}
		}
	}
	rep(i,n) cout<<a[i]<<' ';

	return 0;
}