#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

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
vi g[300009];
vi lf;
int h[300009],par[300009];
vector<pii> bt[300009];
bool vis[300009];
int mxh,mxix;
void dfs(int v,int p){
	h[v] = h[p]+1;
	if(h[v]>mxh) mxh=h[v],mxix=v;
	vis[v] = 1;
	par[v] = p;
	bool fg=0;
	trav(i,g[v]){
		if(!vis[i]){
			dfs(i,v);
			fg=1;
		}
	}
	if(!fg){
		trav(i,g[v]){
			if(i!=p){
				bt[v].pb(mp(h[i],i));
				if(sz(bt[v])==2) break;
			}
		}
		lf.pb(v);
	}
}
vi ans;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,k;cin>>n>>m>>k;
	rep(i,m){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	if(mxh>=n/k){
		cout<<"PATH\n";
		cout<<mxh<<'\n';
		while(mxix){
			cout<<mxix<<' ';
			mxix = par[mxix];
		}
	}
	else{
		cout<<"CYCLES\n";
		rep(ii,k){
			ans.clear();
			int i = lf[ii];
			sort(all(bt[i]));
			if((h[i]-bt[i][0].fst+1)%3){
				int ix = i;
				while(ix!=bt[i][0].snd){
					ans.pb(ix);
					ix = par[ix];
				}
				ans.pb(ix);
				cout<<sz(ans)<<'\n';
				trav(j,ans) cout<<j<<' ';
				cout<<'\n';
			}
			else if((h[i]-bt[i][1].fst+1)%3){
				int ix = i;
				while(ix!=bt[i][1].snd){
					ans.pb(ix);
					ix = par[ix];
				}
				ans.pb(ix);
				cout<<sz(ans)<<'\n';
				trav(j,ans) cout<<j<<' ';
				cout<<'\n';
			}
			else{
				ans.pb(i);
				int ix = bt[i][1].snd;
				while(ix!=bt[i][0].snd){
					ans.pb(ix);
					ix = par[ix];
				}
				ans.pb(ix);
				cout<<sz(ans)<<'\n';
				trav(j,ans) cout<<j<<' ';
				cout<<'\n';
			}
		}
	}
	return 0;
}