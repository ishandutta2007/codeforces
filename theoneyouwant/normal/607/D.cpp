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
// #define int long long int
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

int add(int a, int b){
	return ((ll)a + b)%MOD;
}

int mul(int a, int b){
	return ((ll)a * b)%MOD;
}

int fastpow(int a, int p){
	if(p == 0) return 1;
	int z = fastpow(a, p/2);	
	z = mul(z, z);
	if(p%2) z = mul(z, a);
	return z;
}


struct Segtree{

    v32 t, lazy;

    Segtree(int n) {
        t.assign(4*n, 0);
        lazy.assign(4*n, 1);
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = add(t[v*2], t[v*2+1]);
        }
    }

    void push(int v){
    	if(lazy[v] != 1){
    		t[v*2] = mul(t[v*2], lazy[v]);
	        lazy[v*2] = mul(lazy[v*2],lazy[v]);
	        t[v*2+1] = mul(t[v*2+1],lazy[v]);
	        lazy[v*2+1] = mul(lazy[v*2+1],lazy[v]);
    	}
        lazy[v] = 1;
    }

    void update(int v, int tl, int tr, int l, int r, int addend){
        if(l > r){
            return;
        }
        if(l <= tl && tr <= r){
            t[v] = mul(t[v], addend);
            lazy[v] = mul(lazy[v], addend);
        } else {
            push(v);
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = add(t[v*2], t[v*2+1]);
        }
    }

    void point_update(int v, int tl, int tr, int pos, int addend){
    	if(pos < tl || pos > tr) return;
    	if(tl == tr){
    		t[v] = addend;
    	}
    	else{
    		push(v);
    		int tm = (tl + tr) / 2;
    		point_update(v*2, tl, tm, pos, addend);
            point_update(v*2+1, tm+1, tr, pos, addend);
            // cout<<t[v*2]<<" "<<t[v*2+1]<<ln;
            t[v] = add(t[v*2], t[v*2+1]);
    	}
    }

    int query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l <= tl && tr <= r){
            return t[v];
        }
        push(v);
        int tm = (tl + tr)/2;
        return add(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
} s(400002);

int ent[LIM], ex[LIM], curr = 0;
v32 adj[LIM];
bool visited[LIM];
int child[LIM] = {0};
int n;
int val[LIM] = {0};
int par[LIM] = {0};

void dfs(int node){
	
	visited[node] = 1;
	ent[node] = curr++;

	forstl(r, adj[node]){
		if(visited[r]) continue;
		dfs(r);
	}
	
	ex[node] = curr++;
}

int get_query(int pt){
	return s.query(1, 0, 2*n-1, ent[pt], ex[pt]);
}

int get_factor(int v){
	int act_ans = s.query(1, 0, 2*n-1, ex[v], ex[v]);
	act_ans = mul(act_ans, fastpow(val[v], MOD-2));
	return act_ans;
}

signed main(){
	fastio;

	int u = read(), q = read();
	
	vector<pair<int,p32>> queries;

	int vertices = 0;

	forn(i,q){
		int x = read();
		if(x == 1){
			vertices++;
			int p = read(), v = read();
			p--; 
			par[vertices] = p;
			queries.pb(mp(1,mp(p,v)));
			adj[p].pb(vertices);
			adj[vertices].pb(p);
		}
		else{
			int v = read();
			v--;
			queries.pb(mp(2,mp(v,0)));
		}
	}

	dfs(0);
	val[0] = u;
	n = vertices+1;

	s.point_update(1, 0, 2*n-1, ent[0], u);
	s.point_update(1, 0, 2*n-1, ex[0], u);

	child[0]++;
	vertices = 0;

	forstl(r, queries){
		if(r.fi == 1){
			int p = r.se.fi, v = r.se.se;
			vertices++;
			child[vertices]++;
			val[vertices] = v;

			int vall = mul(fastpow(child[p], MOD-2), child[p]+1);
			s.update(1, 0, 2*n-1, ent[p], ex[p], vall);
			
			child[p]++;
			// cout<<"OKAY "<<p<<" "<<get_factor(p)<<ln;

			int currval = mul(v, get_factor(p));

			s.point_update(1, 0, 2*n-1, ent[vertices], currval);
			s.point_update(1, 0, 2*n-1, ex[vertices], currval);
			// cout<<"AFTER "<<p<<" "<<get_factor(p)<<ln;

		}
		else{
			int v = r.se.fi;
			int root_zero_ans = get_query(v);

			// forn(i,4) cout<<i<<" "<<get_factor(i)<<ln;

			root_zero_ans = mul(root_zero_ans, child[v]);

			int act_ans = get_factor(v);
			act_ans = mul(act_ans, 2);

			root_zero_ans = mul(root_zero_ans, fastpow(act_ans, MOD-2));
			cout<<root_zero_ans<<ln;
		}
	}

	return 0;
}