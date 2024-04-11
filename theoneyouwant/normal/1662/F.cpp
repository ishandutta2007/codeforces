//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
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

struct Tree_max {
	typedef p32 T;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree_max(int n = 0, T def = make_pair(INT_MIN, 0)) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = make_pair(INT_MIN, 0), rb = make_pair(INT_MIN, 0);
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct Tree_min {
	typedef p32 T;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree_min(int n = 0, T def = make_pair(INT_MAX, 0)) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = make_pair(INT_MAX, 0), rb = make_pair(INT_MAX, 0);
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

v32 ar, al;

void getr(int l, int r, int bnd, Tree_min &tr) {
	if(l >= r)
		return;
	p32 p = tr.query(l, r);
	if(p.first > bnd)
		return;
	ar.push_back(p.second);
	getr(l, p.second, bnd, tr);
	getr(p.second + 1, r, bnd, tr);
}

void getl(int l, int r, int bnd, Tree_max &tr) {
	if(l >= r)
		return;
	p32 p = tr.query(l, r);
	if(p.first < bnd)
		return;
	al.push_back(p.second);
	getl(l, p.second, bnd, tr);
	getl(p.second + 1, r, bnd, tr);
}


int main(){
	fastio;
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		a--; b--;
		v32 p(n);
		forn(i, n)
			cin >> p[i];
		v32 pr(n), pl(n);
		forn(i, n) {
			pr[i] = i + p[i];
			pl[i] = i - p[i];
		}
		Tree_max tmx(n);
		Tree_min tmn(n);
		forn(i, n) {
			tmn.update(i,make_pair(pl[i], i));
			tmx.update(i,make_pair(pr[i], i));
		}
		queue <int> q;
		v32 d(n,int(1e9));
		d[a] = 0;
		q.push(a);
		while(!q.empty()) {
			int v = q.front();
			q.pop();

			al.clear();
			ar.clear();
			getl(max(pl[v], 0), v, v, tmx);
			getr(v+1, min(pr[v]+1, n), v, tmn);
			for(int u : ar) {
				if(d[u] == int(1e9)) {
					d[u] = d[v] + 1;
					tmn.update(u, make_pair(INT_MAX, u));
					tmx.update(u, make_pair(INT_MIN, u));
					q.push(u);
				}
			}
			for(int u : al) {
				if(d[u] == int(1e9)) {
					d[u] = d[v] + 1;
					tmx.update(u, make_pair(INT_MIN, u));
					tmn.update(u, make_pair(INT_MAX, u));
					q.push(u);
				}
			}
		}
		//forn(i,n)
		//	cout << d[i] << " ";
		//cout << endl;
		cout << d[b] << endl;
	}
	


	return 0;
}