//#define BITSET64BIT 1
#ifdef BITSET64BIT
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker,"/stack:200000000")
*/
#define endl '\n'

// Shortcut

// #define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(h13, a) cout << h13 << ' '; cout << endl;
#define PrintVl(a) Fora(h13, a) cout << h13 << endl;
#define PrintA(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << endl;
#define Ptest(x) return cout << x, 0;
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){                                                                     \\
    string _sDEB = #args;                                                                   \\
    replace(_sDEB.begin(), _sDEB.end(), ',', ' ');                                          \\
    stringstream _ssDEB(_sDEB);                                                             \\
    istream_iterator<string> _itDEB(_ssDEB);                                                \\
    DEB(_itDEB, args);                                                                      \\
}
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
// #define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

// Data Structure

// Policy based data structures                                                             \\
   Support find_by_order(int k): return an iterator to the k-th smallest element,           \\
                                 counting from 0                                            \\
           order_of_key(int k): return the number of items strictly smaller than k          \\
   For ordered_multiset and ordered_multimap, lower_bound() and upper_bound() are swapped

template <typename T> using ordered_set =
tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_map =
tree <Key, T, less <Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =
tree <T, null_type, less_equal <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_multimap =
tree <Key, T, less_equal <Key>, rb_tree_tag, tree_order_statistics_node_update>;

#define y0 _y0_
#define y1 _y1_
#define div divi
// typedef long long ll;
// typedef long double ld;
// typedef vector <int> vi;
// typedef vector <ll> vll;
// typedef vector <ld> vld;
// typedef vector <string> vs;
// typedef pair <int, int> pii;
// typedef pair <ll, ll> pll;
// typedef vector <vi > vvi;
// typedef vector <vll > vvll;
// typedef vector <pii > vpii;
// typedef vector <pll > vpll;

const int N = 5e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
// ll infll = 1e18 + 7;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void YES(){cout<<"YES\n";} void NO(){cout<<"NO\n";}
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 998244353;

bool DEBUG = 0;
const int MAXN = 500005;

class SegmentTree {
	const ll inf = 1e18;
	int n, n0;
	ll max_v[4*N], smax_v[4*N], max_c[4*N];
	ll min_v[4*N], smin_v[4*N], min_c[4*N];
	ll sum[4*N];
	ll len[4*N], ladd[4*N], lval[4*N];

	void update_node_max(int k, ll x) {
		sum[k] += (x - max_v[k]) * max_c[k];

		if(max_v[k] == min_v[k]) {
			max_v[k] = min_v[k] = x;
		} else if(max_v[k] == smin_v[k]) {
			max_v[k] = smin_v[k] = x;
		} else {
			max_v[k] = x;
		}

		if(lval[k] != inf && x < lval[k]) {
			lval[k] = x;
		}
	}
	void update_node_min(int k, ll x) {
		sum[k] += (x - min_v[k]) * min_c[k];

		if(max_v[k] == min_v[k]) {
			max_v[k] = min_v[k] = x;
		} else if(smax_v[k] == min_v[k]) {
			min_v[k] = smax_v[k] = x;
		} else {
			min_v[k] = x;
		}

		if(lval[k] != inf && lval[k] < x) {
			lval[k] = x;
		}
	}

	void push(int k) {
		if(n0-1 <= k) return;

		if(lval[k] != inf) {
			updateall(2*k+1, lval[k]);
			updateall(2*k+2, lval[k]);
			lval[k] = inf;
			return;
		}

		if(ladd[k] != 0) {
			addall(2*k+1, ladd[k]);
			addall(2*k+2, ladd[k]);
			ladd[k] = 0;
		}

		if(max_v[k] < max_v[2*k+1]) {
			update_node_max(2*k+1, max_v[k]);
		}
		if(min_v[2*k+1] < min_v[k]) {
			update_node_min(2*k+1, min_v[k]);
		}

		if(max_v[k] < max_v[2*k+2]) {
			update_node_max(2*k+2, max_v[k]);
		}
		if(min_v[2*k+2] < min_v[k]) {
			update_node_min(2*k+2, min_v[k]);
		}
	}

	void update(int k) {
		sum[k] = sum[2*k+1] + sum[2*k+2];

		if(max_v[2*k+1] < max_v[2*k+2]) {
			max_v[k] = max_v[2*k+2];
			max_c[k] = max_c[2*k+2];
			smax_v[k] = max(max_v[2*k+1], smax_v[2*k+2]);
		} else if(max_v[2*k+1] > max_v[2*k+2]) {
			max_v[k] = max_v[2*k+1];
			max_c[k] = max_c[2*k+1];
			smax_v[k] = max(smax_v[2*k+1], max_v[2*k+2]);
		} else {
			max_v[k] = max_v[2*k+1];
			max_c[k] = max_c[2*k+1] + max_c[2*k+2];
			smax_v[k] = max(smax_v[2*k+1], smax_v[2*k+2]);
		}

		if(min_v[2*k+1] < min_v[2*k+2]) {
			min_v[k] = min_v[2*k+1];
			min_c[k] = min_c[2*k+1];
			smin_v[k] = min(smin_v[2*k+1], min_v[2*k+2]);
		} else if(min_v[2*k+1] > min_v[2*k+2]) {
			min_v[k] = min_v[2*k+2];
			min_c[k] = min_c[2*k+2];
			smin_v[k] = min(min_v[2*k+1], smin_v[2*k+2]);
		} else {
			min_v[k] = min_v[2*k+1];
			min_c[k] = min_c[2*k+1] + min_c[2*k+2];
			smin_v[k] = min(smin_v[2*k+1], smin_v[2*k+2]);
		}
	}

	void _update_min(ll x, int a, int b, int k, int l, int r) {
		if(b <= l || r <= a || max_v[k] <= x) {
			return;
		}
		if(a <= l && r <= b && smax_v[k] < x) {
			update_node_max(k, x);
			return;
		}

		push(k);
		_update_min(x, a, b, 2*k+1, l, (l+r)/2);
		_update_min(x, a, b, 2*k+2, (l+r)/2, r);
		update(k);
	}

	void _update_max(ll x, int a, int b, int k, int l, int r) {
		if(b <= l || r <= a || x <= min_v[k]) {
			return;
		}
		if(a <= l && r <= b && x < smin_v[k]) {
			update_node_min(k, x);
			return;
		}

		push(k);
		_update_max(x, a, b, 2*k+1, l, (l+r)/2);
		_update_max(x, a, b, 2*k+2, (l+r)/2, r);
		update(k);
	}

	void addall(int k, ll x) {
		max_v[k] += x;
		if(smax_v[k] != -inf) smax_v[k] += x;
		min_v[k] += x;
		if(smin_v[k] != inf) smin_v[k] += x;

		sum[k] += len[k] * x;
		if(lval[k] != inf) {
			lval[k] += x;
		} else {
			ladd[k] += x;
		}
	}

	void updateall(int k, ll x) {
		max_v[k] = x; smax_v[k] = -inf;
		min_v[k] = x; smin_v[k] = inf;
		max_c[k] = min_c[k] = len[k];

		sum[k] = x * len[k];
		lval[k] = x; ladd[k] = 0;
	}

	void _add_val(ll x, int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) {
			return;
		}
		if(a <= l && r <= b) {
			addall(k, x);
			return;
		}

		push(k);
		_add_val(x, a, b, 2*k+1, l, (l+r)/2);
		_add_val(x, a, b, 2*k+2, (l+r)/2, r);
		update(k);
	}

	void _update_val(ll x, int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) {
			return;
		}
		if(a <= l && r <= b) {
			updateall(k, x);
			return;
		}

		push(k);
		_update_val(x, a, b, 2*k+1, l, (l+r)/2);
		_update_val(x, a, b, 2*k+2, (l+r)/2, r);
		update(k);
	}

	ll _query_max(int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) {
			return -inf;
		}
		if(a <= l && r <= b) {
			return max_v[k];
		}
		push(k);
		ll lv = _query_max(a, b, 2*k+1, l, (l+r)/2);
		ll rv = _query_max(a, b, 2*k+2, (l+r)/2, r);
		return max(lv, rv);
	}

	ll _query_min(int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) {
			return inf;
		}
		if(a <= l && r <= b) {
			return min_v[k];
		}
		push(k);
		ll lv = _query_min(a, b, 2*k+1, l, (l+r)/2);
		ll rv = _query_min(a, b, 2*k+2, (l+r)/2, r);
		return min(lv, rv);
	}

	ll _query_sum(int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) {
			return 0;
		}
		if(a <= l && r <= b) {
			return sum[k];
		}
		push(k);
		ll lv = _query_sum(a, b, 2*k+1, l, (l+r)/2);
		ll rv = _query_sum(a, b, 2*k+2, (l+r)/2, r);
		return lv + rv;
	}

public:
	SegmentTree(int n) {
		SegmentTree(n, nullptr);
	}

	SegmentTree(int n, ll *a) : n(n) {
		n0 = 1;
		while(n0 < n) n0 <<= 1;

		for(int i=0; i<2*n0; ++i) ladd[i] = 0, lval[i] = inf;
		len[0] = n0;
		for(int i=0; i<n0-1; ++i) len[2*i+1] = len[2*i+2] = (len[i] >> 1);

		for(int i=0; i<n; ++i) {
			max_v[n0-1+i] = min_v[n0-1+i] = sum[n0-1+i] = (a != nullptr ? a[i] : 0);
			smax_v[n0-1+i] = -inf;
			smin_v[n0-1+i] = inf;
			max_c[n0-1+i] = min_c[n0-1+i] = 1;
		}

		for(int i=n; i<n0; ++i) {
			max_v[n0-1+i] = smax_v[n0-1+i] = -inf;
			min_v[n0-1+i] = smin_v[n0-1+i] = inf;
			max_c[n0-1+i] = min_c[n0-1+i] = 0;
		}
		for(int i=n0-2; i>=0; i--) {
			update(i);
		}
	}

	// range minimize query
	void update_min(int a, int b, ll x) {
		_update_min(x, a, b, 0, 0, n0);
	}

	// range maximize query
	void update_max(int a, int b, ll x) {
		_update_max(x, a, b, 0, 0, n0);
	}

	// range add query
	void add_val(int a, int b, ll x) {
		_add_val(x, a, b, 0, 0, n0);
	}

	// range update query
	void update_val(int a, int b, ll x) {
		_update_val(x, a, b, 0, 0, n0);
	}

	// range minimum query
	ll query_max(int a, int b) {
		return _query_max(a, b, 0, 0, n0);
	}

	// range maximum query
	ll query_min(int a, int b) {
		return _query_min(a, b, 0, 0, n0);
	}

	// range sum query
	ll query_sum(int a, int b) {
		return _query_sum(a, b, 0, 0, n0);
	}
};

ll ans;

int n;
string s;

ll a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    SegmentTree seg(n, a);
    
    int t = 0;
    For(i, 0, n){
        char c; cin >> c;
        if (c == '1'){
            t++;
            // cout << i << ' ' << t << endl;
            if (i + 1 > i - t + 1) seg.add_val(i - t + 1, i + 1, 1);
            if (i - t + 1 > 0) seg.update_max(0, i - t + 1, t);
            // ForE(j, 0, i){
            //     cout << seg.query_sum(j, j + 1) << ' ';
            // } cout << endl;
        }
        else{
            t = 0;
        }
        ans += seg.query_sum(0, i + 1);
    }
    cout << ans;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/