#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int a[200009];
vi g[200009];
bool vis[200009];
map<int,ll> ans;
void dfs(int v,map<int,ll>& x){
	x[a[v]]=1;ans[a[v]]++;
	vis[v]=1;
	trav(i,g[v]){
		if(!vis[i]) {
			map<int,ll> y;
			dfs(i,y);
			trav(j,y){
				trav(k,x){
					ans[__gcd(j.fst,k.fst)]+=1ll*j.snd*k.snd;
				}
			}
			trav(j,y){
				x[__gcd(j.fst,a[v])]+=j.snd;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>a[i+1];
	rep(i,n-1) {
		int x,y;cin>>x>>y;
		g[x].pb(y);g[y].pb(x);
	}
	map<int,ll> y;
	dfs(1,y);
	trav(i,ans) cout<<i.fst<<' '<<i.snd<<'\n';
	return 0;
}