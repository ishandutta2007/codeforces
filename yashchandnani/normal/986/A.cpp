#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//4/
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
int a[100009];
bool vis[100009];
vi g[100009],h[109];
priority_queue<int> q[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,k,s;cin>>n>>m>>k>>s;
	rep(i,n){
		cin>>a[i];
		h[a[i]].pb(i);
	}
	rep(i,m){
		int u,v;cin>>u>>v;u--;v--;
		g[u].pb(v);g[v].pb(u);
	}
	repA(i,1,k){
		deque<pii> u;
		fill(vis);
		trav(j,h[i]) u.push_back(mp(0,j)),vis[j]=1;
		while(!u.empty()){
			pii z = u.front();
			u.pop_front();
			q[z.snd].push(z.fst);
			trav(j,g[z.snd]){
				if(!vis[j]){
					vis[j] = 1;
					u.push_back(mp(z.fst-1,j));
				}
			}
		}
	}
	rep(i,n){
		int ss = 0;
		rep(j,s){
			ss+=q[i].top();
			q[i].pop();
		}
		cout<<-ss<<' ';
	}
	return 0;
}