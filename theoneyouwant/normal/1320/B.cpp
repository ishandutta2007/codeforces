//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	int n,m; cin>>n>>m;
	v32 adj[n];
	v32 adj2[n];

	forn(i,m){
		int u,v; cin>>u>>v;
		u--; v--;
		adj[v].pb(u);
		adj2[u].pb(v);
	}

	int height[n] = {0};
	priority_queue<p32> q;
	int visited[n] = {0};

	int k; cin>>k;
	int mi = 0, ma = 0;
	int inp[k] = {0};
	forn(i,k){
		cin>>inp[i];
		inp[i]--;
	}

	q.push(mp(0,inp[k-1]));
	visited[inp[k-1]] = 1;

	while(!q.empty()){
		auto t = q.top();
		q.pop();
		height[t.se] = -t.fi;
		// cout<<t.fi<<" "<<t.se<<ln;
		forstl(r,adj[t.se]){
			if(visited[r]) continue;
			visited[r] = 1;
			q.push(mp(-(height[t.se]+1),r));
		}
	}

	// cout<<height[3]<<" WHAT"<<ln;

	forn(i,k-1){
		// cout<<i<<" "<<height[inp[i]]<<" "<<height[inp[i+1]]<<ln;
		if(height[inp[i]]-1 != height[inp[i+1]]){
			ma++;
			mi++;
		}else{
			int g = 0;
			forstl(r,adj2[inp[i]]){
				if(height[r] == height[inp[i]]-1) g++;
			}
			if(g>1) ma++;
		}
		// cout<<mi<<" added "<<ma<<ln;
	}
	cout<<mi<<" "<<ma<<ln;

	return 0;
}