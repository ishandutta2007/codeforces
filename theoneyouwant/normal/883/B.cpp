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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,k;
int r[LIM], maxrank[LIM], minrank[LIM];
v32 adj[LIM], adj2[LIM];
vp32 inp[LIM];
vector<bool> visited;
vector<int> ans;
int done[LIM];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

bool cycle_check(){
	topological_sort();
	int marked[n] = {0};
	bool pos = 1;
	forn(i,n){
		int ind = ans[i];
		marked[ind] = 1;
		forstl(r, adj[ind]){
			if(marked[r]) pos = 0;
		}
	}
	return pos;
}

int main(){
	fastio;

	n = read(), m = read(), k = read();

	forn(i,n) r[i] = read();

	forn(i,m){
		int x = read(), y = read();
		x--; y--;
		adj[x].pb(y);
		adj2[y].pb(x);
	}

	if(cycle_check() == 0){
		cout<<-1<<ln;
		return 0;
	}
	bool check = 1;
	forn(i,n){
		if(r[i] != 0){
			minrank[i] = r[i];
			maxrank[i] = r[i];
		}
		else{
			minrank[i] = 1;
			maxrank[i] = k;
		}
	}
	forn(i,n){
		int ind = ans[i];
		forstl(r, adj[ind]){
			maxrank[r] = min(maxrank[r], maxrank[ind] - 1);
		}
	}

	rforn(i,n-1){
		int ind = ans[i];
		forstl(r, adj2[ind]){
			minrank[r] = max(minrank[r], minrank[ind] + 1);
		}
	}

	forn(i,n) if(maxrank[i] < minrank[i]) check = 0;

	forn(i,n){
		if(minrank[i] <= 0 || maxrank[i] > k) check = 0;
	}

	if(check == 0){
		cout<<-1<<ln;
		return 0;
	}

	set<p32> s;

	forn(i,n){
		inp[minrank[i]].pb(mp(maxrank[i], i));
	}

	forsn(i,1,k+1){
		forstl(r, inp[i]){
			s.insert(r);
		}
		if(s.size() == 0){
			check = 0;
			continue;
		}
		auto val = *s.begin();
		r[val.se] = i;
		s.erase(s.begin());
		
		while(!s.empty() && ((*s.begin()).fi == i)){
			val = *s.begin();
			s.erase(s.begin());
			r[val.se] = i;
		}
	}

	forn(i,n){
		done[r[i]] = 1;
	}
	forsn(i,1,k+1){
		if(!done[i]) check = 0;
	}

	forn(i,n){
		if(r[i] <= 0) check = 0;
		if(r[i] > maxrank[i]) check = 0;
	}

	// forn(i,n) cout<<r[i]<<" ";
	// cout<<ln;

	if(check == 0) cout<<-1<<ln;
	else {
		forn(i,n) cout<<r[i]<<" ";
		cout<<ln;
	}

	return 0;
}