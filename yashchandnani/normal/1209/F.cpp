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
vector<pii> g[1000009];
int ix[1000009];
ll fns[1000009];
bool vis[1000009];
const ll mod = 1e9+7;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int m;cin>>m;
	int nn = n;
	repA(i,1,m){
		string s = to_string(i);
		int x,y;
		cin>>x>>y;
		int lst = x;
		rep(i,sz(s)-1){
			n++;
			g[lst].pb(mp(n,s[i]-'0'));
			g[n].pb(mp(lst,s[sz(s)-1-i]-'0'));
			lst = n;
		}
		g[lst].pb(mp(y,s[sz(s)-1]-'0'));
		g[y].pb(mp(lst,s[0]-'0'));
	}
	priority_queue<pair<pii,pii>,vector<pair<pii,pii>>,greater<pair<pii,pii>>> q;
	q.push(mp(mp(0,0),mp(1,0)));
	pii gg = mp(0,0);
	int t =0;
	while(!q.empty()){
		pair<pii,pii> z = q.top();
		q.pop();
		if(vis[z.snd.fst]) continue;
		fns[z.snd.fst] = (fns[z.snd.snd]*10+z.fst.snd)%mod;
		vis[z.snd.fst]=1;
		if(z.fst==gg) {
			ix[z.snd.fst] = t;
		}
		else {
			t++;
			ix[z.snd.fst] = t;
			gg=z.fst;
		}
		trav(j,g[z.snd.fst]){
			if(!vis[j.fst]){
				q.push(mp(mp(t,j.snd),mp(j.fst,z.snd.fst)));
			}
		}
	}
	repA(i,2,nn){
		cout<<fns[i]<<'\n';
	}
	return 0;
}