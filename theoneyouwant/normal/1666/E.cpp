#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <complex>
#include <iterator>
#include <regex>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define F0R(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORd(i,a,b) for (int i = (b); i >= (a); i--)
#define trav(a, x) for (auto& a : x)

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MAX_N = 100011;
const ll INF = (1<<29) + 123;
const ll MOD = 1000000007; // 998244353
const ld PI = 4*atan((ld)1);

template <typename T> bool ckmin(T& a, const T& b) { return a > b ? a=b, 1 : 0; }
template <typename T> bool ckmax(T& a, const T& b) { return b > a ? a=b, 1 : 0; }

void dbg_out () { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out (Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }

// from @jacob.b.zhang :)
template<typename T> class SafeVector : public vector<T> {
    public:
        using vector<T>::vector;
 
        typename vector<T>::reference operator[](size_t n) {
            return vector<T>::at(n);
        }
 
        typename vector<T>::const_reference operator[](size_t n) const {
            return vector<T>::at(n);
        }
};

#ifdef DBG
#define dbg(desc, ...) cerr << '(' << desc << "): "; dbg_out(__VA_ARGS__);
#define vector SafeVector
#else
#define dbg(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MX = 1e5+5;
int a[MX];
int L, n;
bool check(int ans1, int ans2) {
    int left = 0, right = 0;
    FOR(i, 1, n) {
        // dbg(i, left, right);
        if (left + ans1 > a[i+1]) return 0;
        left = max(a[i], left + ans1);
        if (right + ans2 < a[i]) return 0;
        right = min(a[i+1], right + ans2);
    }
    if (left > L || right < L) return 0;
    return 1;
}

void recover_ans(int ans1, int ans2) {
    int left = 0, right = 0;
    vpi v; v.pb({0, 0});
    FOR(i, 1, n) {
        // dbg(i, left, right);
        left = max(a[i], left + ans1);
        right = min(a[i+1], right + ans2);
        v.pb({left, right});
    }
    int cur = L;
    vi ans; ans.pb(cur);
    F0Rd(i, n) {
        // v[i].f, v[i].s
        // dbg(v[i].f, v[i].s, cur);
        if (cur - v[i].f > ans2) {
            cur -= ans2;
        } else {
            cur = v[i].f;
        }
        ans.pb(cur);
    }
    reverse(all(ans));
    F0R(i, n) cout << ans[i] << " " << ans[i+1] << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> L >> n;
    F0R(i, n) cin >> a[i+1]; a[0] = 0; a[n+1] = L;
    // cerr << check(2, 8) << nl;
    int lo = 1, hi = 1e9; 
    while (lo < hi) {
        int mid = (lo+hi)/2;
        int l = mid, h = 1e9+1;
        while (l < h) {
            int m = (l+h)/2;            
            if (check(mid, m)) h = m;
            else l = m+1;
        }
        if (l > 1e9) hi = mid;
        else lo = mid+1; 
    }
    int ans1 = lo-1;
    int l = ans1, h = 1e9;
    while (l < h) {
        int m = (l+h)/2;
        if (check(ans1, m)) h = m;
        else l = m+1;
    }
    // cout << ans1 << " " << l << nl;
    recover_ans(ans1, l);
    return 0;
}