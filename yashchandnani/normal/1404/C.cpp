#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
	  	  tree_order_statistics_node_update>;
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
int a[300009];
int ans[300009];
int fns[300009];
struct Treex {
	typedef int T;
	const T LOW = 0;
	T f(T a, T b) { return a+b; }

	int n;
	vi s;
	Treex() {}
	Treex(int m, T def=0) { init(m, def); }
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
	int n,q;cin>>n>>q;
	Tree<pii> T;
	vector<pii> vals;
	repA(i,1,n) {
		cin>>a[i];
		a[i]-=i;
		a[i]=-a[i];
		if(a[i]==0){
			T.insert(mp(-i,i));
			ans[i]=i;
		}
		else if(a[i]<0){
			ans[i]=-1;
		}
		else if(a[i]<=sz(T)){
			ans[i]=(*T.find_by_order(a[i]-1)).fst;
			ans[i]=-ans[i];
			T.insert(mp(-ans[i],i));
		}
		else ans[i]=-1;
		if(ans[i]!=-1){
			vals.pb(mp(ans[i],i));
		}
	}
	sort(all(vals));
	vector<pair<pii,int>> qq;
	rep(i,q){
		int x,y;cin>>x>>y;
		qq.pb(mp(mp(x,y),i));
	}
	sort(all(qq));
	reverse(all(qq));
	Treex T2(n+7);
	trav(i,qq){
		while(sz(vals)&&vals.back().fst>i.fst.fst){
			T2.update(vals.back().snd,1);
			vals.pop_back();
		}
		fns[i.snd] = T2.query(i.fst.fst+1,n-i.fst.snd+1);
	}
	rep(i,q) cout<<fns[i]<<'\n';
	return 0;
}