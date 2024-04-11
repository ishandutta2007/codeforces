//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define int long long int
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
const int LIM=3e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

v32 adj[LIM];
vector<bool> visited;
vector<int> tin, low;
int timer;
v32 is_bridge[LIM];
int n, m;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    forn(j, adj[v].size()){
    	int to = adj[v][j];
    	if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
        	dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
            	is_bridge[v][j] = 1;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


int link[LIM] = {0};
int sz[LIM] = {0};
int mx[LIM];
int mi[LIM];

int find(int x){
	if(x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b] = a;
	mx[a] = max(mx[b], mx[a]);
	mi[a] = min(mi[a], mi[b]);
}


struct Segtree{

    v32 t, lazy, sz;

    Segtree(int n) {
        t.assign(4*n, 0);
        lazy.assign(4*n, 0);
        sz.assign(4*n, 0);
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
            sz[v] = 1;
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
            sz[v] = sz[v*2] + sz[v*2+1];
        }
    }

    void push(int v){
        t[v*2] += sz[v*2]*lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += sz[v*2+1]*lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int addend){
        if(l > r){
            return;
        }
        if(l <= tl && tr <= r){
            t[v] += sz[v]*addend;
            lazy[v] += addend;
            // if(addend == -1) cout<<t[v]<<" "<<lazy[v]<<ln;
        } else {
            push(v);
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = t[v*2]+t[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l <= tl && tr <= r){
            return t[v];
        }
        push(v);
        int tm = (tl + tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};


signed main(){
	fastio;

	cin>>n>>m;
	forn(i,m){
		int a, b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		is_bridge[a].pb(b);
		is_bridge[b].pb(a);
	}

	forn(i,n){
		forn(j,is_bridge[i].size()){
			is_bridge[i][j] = 0;
		}
	}

	find_bridges();

	map<p32,bool> m;
	forn(i,n){
		forn(j,is_bridge[i].size()){
			if(is_bridge[i][j]){
				m[mp(i,adj[i][j])] = 1;
			}
		}
	}
	forn(i,n){
		forn(j,is_bridge[i].size()){
			int to = adj[i][j];
			if(m[mp(to,i)]) is_bridge[i][j] = 1;
		}
	}

	forn(i,LIM){
		sz[i] = 1;
		link[i] = i;
		mx[i] = i;
		mi[i] = i;
	}

	forn(i,n){
		forn(j,adj[i].size()){
			if(is_bridge[i][j]) continue;
			int r = adj[i][j];
			// cout<<"not bridge "<<i<<" "<<r<<ln;
			unite(i, r);
		}
	}

	set<int> s;
	forn(i,n) s.insert(find(i));

	int intervals[LIM];

	forn(i,LIM) intervals[i] = n;

	forstl(r,s){
		if(sz[r]>1){
			intervals[mi[r]] = min(intervals[mi[r]], mx[r]);
		}
	}

	rforn(i,LIM-2){
		intervals[i] = min(intervals[i], intervals[i+1]);
	}

	Segtree seg(n);
	int aaa[n] = {0};
	seg.build(aaa,1,0,n-1);
	int q; cin>>q;
	vector<pair<p32, int>> v;
	int answers[q] = {0};
	
	forn(i,q){
		int l, r;
		cin>>l>>r;
		l--; r--;
		v.pb(mp(mp(l,r),i));
	}
	sort(all(v));
	forn(i,n){
		// cout<<i<<" "<<intervals[i]-1<<ln;
		// from i to intervals[i]-1, add 1 to each position
		seg.update(1,0,n-1,i,intervals[i]-1,1);
	}
	forn(i,n){
		// cout<<"val at "<<i<<" "<<seg.query(1,0,n-1,i,i)<<ln;
	}
	int last = 0;
	forstl(r,v){
		forsn(i, last, r.fi.fi){
			// cout<<"updating "<<i<<" "<<intervals[i]<<ln;
			seg.update(1,0,n-1,i,intervals[i]-1,-1);
		}
		last = r.fi.fi;
		answers[r.se] = seg.query(1,0,n-1,r.fi.fi,r.fi.se);
	}
	forn(i,q){
		cout<<answers[i]<<ln;
	}


	return 0;
}