#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld PI = acos(-1);

typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;

	vector<base> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft (a0, invert);
	fft (a1, invert);

	double ang = 2*PI/n * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

_ void source() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n + 1), kek, l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] < x) {
            kek.pb(i);
        }
    }
    int ans0 = 0, kk = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= x) {
            kk++;
        }
        else {
            if (kk) ans0 += kk * (kk + 1) / 2;
            kk = 0;
        }
    }
    if (kk) ans0 += kk * (kk + 1) / 2;
    cout << ans0 << ' ';
    l[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] < x) {
            l[i] = 0;
        }
        else {
            l[i] = l[i - 1] + 1;
        }
    }
    r[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i + 1] < x) {
            r[i] = 0;
        }
        else {
            r[i] = r[i + 1] + 1;
        }
    }
    vector<int> a, b;
    for (auto it : kek) {
        a.pb(l[it] + 1);
    }
    reverse(all(kek));
    for (auto it : kek) {
        b.pb(r[it] + 1);
    }
    vector<int> ans;
    multiply(a, b, ans);
    int cur = a.size();
    vector<int> final_ans(n + 1);
    for (int i = 1; i <= a.size(); i++) {
        final_ans[i] = ans[cur - 1];
        cur--;
    }
    for (int i = 1; i <= n; i++) {
        cout << final_ans[i] << ' ';
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}