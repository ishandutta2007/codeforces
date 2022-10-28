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
ll w[200009],w2[200009];
int d[200009];
vi g[200009];
bool vis[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int m;cin>>m;
	ll ans = 0;
	rep(i,n){
		cin>>w[i];
		ans+=w[i];
	}
	rep(i,m){
		int u,v;cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		d[u]++;
		d[v]++;
	}
	int s;cin>>s;
	s--;
	vi v;
	rep(i,n){
		if(i!=s&&d[i]==1){
			v.pb(i);		
		}
	}
	ll cur = 0;
	while(!v.empty()){
		int i = v.back();
		v.pop_back();
		ans-=w[i];
		cur=max(cur,w[i]+w2[i]);
		vis[i]=1;
		trav(j,g[i]){
			if(!vis[j]){
				d[j]--;
				w2[j]=max(w2[j],w2[i]+w[i]);
				if(j!=s&&d[j]==1) {
					v.pb(j);
				}
			}
		}
	}
	cout<<ans+cur;
	return 0;
}