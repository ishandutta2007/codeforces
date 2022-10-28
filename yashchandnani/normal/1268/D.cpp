#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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
string s[2009];
bitset<2009> b1[2009],b2[2009];
vi val, comp, z, cont;
int Time, ncomps;
vector<vi> comps;
void f(vi& v){
	comps.pb(v);
}
template<class G> int dfs(int j, G& g) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G> void scc(G& g) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,n) if (comp[i] < 0) dfs(i, g);
}
vector<vi> g;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>s[i];
	rep(i,n) rep(j,n) b1[i][j] = s[i][j]-'0',b2[i][j]=1-b1[i][j];
	g.resize(n);
	rep(i,n) rep(j,n) if(b1[i][j]) g[i].pb(j);
	scc(g);
	if(ncomps==1){
		cout<<0<<' '<<1<<'\n';
	}
	else{
		int cnt=0;
		trav(i,comps.back()){
			swap(b1[i],b2[i]);
			bitset<2009> cur,tem;
			queue<int> q;
			q.push(i);
			cur[i] = 1;
			while(!q.empty()){
				int z = q.front();
				q.pop();
				tem = (cur^b1[z])&(b1[z]);
				int st = tem._Find_first();
				while(st!=sz(tem)){
					q.push(st);
					cur[st]=1;
					st=tem._Find_next(st);
				}
			}
			bool fg=0;
			rep(i,n){
				if(cur[i]==0) fg=1;
			}
			if(!fg) cnt++; 
			swap(b1[i],b2[i]);
		}
		rep(i,n) swap(b1[i],b2[i]);
		trav(i,comps[0]){
			swap(b1[i],b2[i]);
			bitset<2009> cur,tem;
			queue<int> q;
			q.push(i);
			cur[i] = 1;
			while(!q.empty()){
				int z = q.front();
				q.pop();
				tem = (cur^b1[z])&(b1[z]);
				int st = tem._Find_first();
				while(st!=sz(tem)){
					q.push(st);
					cur[st]=1;
					st=tem._Find_next(st);
				}
			}
			bool fg=0;
			rep(i,n){
				if(cur[i]==0) fg=1;
			}
			if(!fg) cnt++; 
			swap(b1[i],b2[i]);
		}
		repA(i,1,sz(comps)-2) cnt+=sz(comps[i]);
		int ans = cnt;
		if(ans) cout<<1<<' '<<ans<<'\n';
		else if(sz(comps[0])>1&&sz(comps.back())>1) cout<<2<<' '<<sz(comps[0])*sz(comps.back())*2<<'\n';
		else cout<<-1;
	}
	
	return 0;
}