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

    vector < vector<int> > g, gr;
    vector<bool> used;
    vector<int> order, component;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ])
                dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v) {
        used[v] = true;
        component.push_back (v);
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ])
                dfs2 (gr[v][i]);
    }

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		int n,m;
		cin>>n>>m;
		g.clear();
		gr.clear();
		forn(i,n){
			v32 v;
			g.pb(v);
			gr.pb(v);
		}
		used.clear();
		order.clear();
		forn(i,m){
			int x,y;
			cin>>x>>y;
			x--;
			y--;
			if(x == y) continue;
			g[x].pb(y);
			gr[y].pb(x);
		}
		// cout<<"OK"<<endl;
		v32 answer;
		used.assign(n, false);
		int number = 0;
		forn(i,n)
			if(!used[i]) dfs1(i);
			used.assign(n,false);
			forn(i,n){
				int v = order[n-1-i];
				if(!used[v]){
					dfs2(v);
					// cout<<component<<ln;
					if(answer.size() == 0) answer = component;
					if(component.size()>0) number++;
					component.clear();
				}
			}

		if(number>1){
			cout<<"YES"<<ln;
			sort(answer.begin(),answer.end());
			cout<<n-answer.size()<<" "<<answer.size()<<ln;
			int done[n+1] = {0};
			forstl(r,answer) done[r+1] = 1;
			forsn(i,1,n+1) if(done[i] == 0) cout<<i<<" ";
			cout<<ln;
			forsn(i,1,n+1) if(done[i] == 1) cout<<i<<" ";
			cout<<ln;
		} 
		else cout<<"NO"<<ln;

	}

	return 0;
}