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
int sa[100009],sb[100009],ea[100009],eb[100009];
struct Tree {
	typedef int T;
	const T LOW = -1234567890;
	T f(T a, T b) { return max(a, b); }

	int n;
	vi s;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	}
};
struct Tree2 {
	typedef int T;
	const T LOW = 1234567890;
	T f(T a, T b) { return min(a, b); }

	int n;
	vi s;
	Tree2() {}
	Tree2(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vector<pii> v1,v2;
	rep(i,n){
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
		v1.pb(mp(sa[i],i));
		v2.pb(mp(sb[i],i));
	}
	sort(all(v1));
	sort(all(v2));
	Tree T1(n),T2(n);
	Tree2 T3(n),T4(n);
	rep(i,n){
		T3.update(i,eb[v1[i].snd]);
		T4.update(i,ea[v2[i].snd]);
	}
	rep(i,n){
		T1.update(i,sb[v1[i].snd]);
		T2.update(i,sa[v2[i].snd]);
	}
	bool fg=1;
	rep(i,n){
		int s = sb[i], e = eb[i];
		int ix1 = lower_bound(all(v2),mp(s,-1))-v2.begin();
		int ix2 = lower_bound(all(v2),mp(e+1,-1))-v2.begin();
		if(ix1>=ix2) continue;
		int mx = T2.query(ix1,ix2);
		int mn = T4.query(ix1,ix2);
		if(mx>ea[i]||mn<sa[i]) fg=0;
	}
	rep(i,n){
		int s = sa[i], e = ea[i];
		int ix1 = lower_bound(all(v1),mp(s,-1))-v1.begin();
		int ix2 = lower_bound(all(v1),mp(e+1,-1))-v1.begin();
		if(ix1>=ix2) continue;
		int mx = T1.query(ix1,ix2);
		int mn = T3.query(ix1,ix2);
		if(mx>eb[i]||mn<sb[i]) fg=0;
	}
	if(fg) cout<<"YES";
	else cout<<"NO";
	return 0;
}