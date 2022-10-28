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
int a[200009];
int ans[200009];
struct Tree {
	typedef int T;
	const T LOW = 1234567890;
	T f(T a, T b) { return min(a, b); }

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
int fns[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vector<pii> v;
	int hg = 0;
	rep(i,n){
		cin>>a[i];
		hg = max(hg,a[i]);
		a[n+i] = a[i];
		v.pb({a[i],i+n});
	}
	sort(all(v));
	Tree T(n);
	rep(i,n){
		T.update(i,v[i].snd);
	}
	repD(i,n-1,0){
		int r = (a[i]+1)/2;
		int ix = lower_bound(all(v),mp(r,-1))-v.begin();
		ans[i] = T.query(0,ix);
		ix = lower_bound(all(v),mp(a[i],i+n)) - v.begin();
		T.update(ix,i);
	}
	int st=-1;
	rep(i,n){
		if(a[i]==hg)	{
			st = i;
			break;
		}
	}
	if(ans[st]>=2*n){
		rep(i,n) cout<<-1<<' ';
		exit(0);
	}
	st+=n;
	repA(i,n,2*n-1) ans[i] = ans[i-n]+n;
	vector<pii> z(1,{hg,st});
	repD(i,st-1,0){
		while(z.back().fst<a[i]) z.pop_back();
		if(ans[i]>=z.back().snd) ans[i] = ans[z.back().snd];
		z.pb({a[i],i});
	}
	rep(i,n) cout<<ans[i]-i<<' ';
	return 0;
}