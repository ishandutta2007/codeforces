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
int dg[100009],p[100009];
vi g[100009],v[2];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m;cin>>n>>m;
	rep(i,n) cin>>p[i];
	rep(i,m){
		int u,v;cin>>u>>v;
		dg[u]++;
		g[v].pb(u);
	}
	rep(i,n){
		if(dg[i]==0) v[p[i]].pb(i);
	}
	int ans=0;
	while(sz(v[0])!=0||sz(v[1])!=0){
		while(!v[0].empty()){
			int z = v[0].back();
			v[0].pop_back();
			trav(i,g[z]) {dg[i]--;if(dg[i]==0) v[p[i]].pb(i);}
		}
		if(!v[1].empty()){
			ans++;
			while(!v[1].empty()){
					int z = v[1].back();v[1].pop_back();
					trav(i,g[z]) {dg[i]--;if(dg[i]==0) v[p[i]].pb(i);}
			}
		}
	}
	cout<<ans;
	
	return 0;
}