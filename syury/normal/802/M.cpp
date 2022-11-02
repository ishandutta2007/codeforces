#ifndef home
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4a,popcnt,abm,mmx")
#endif // home
#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <type_traits>
#include <ext/rope>
#include <ext/numeric>
#include <ext/pb_ds/priority_queue.hpp>
#include <random>
#include <unordered_set>
#include <forward_list>
#include <initializer_list>
#include <stack>
#include <climits>
#include <bitset>
#include <functional>
#include <utility>
#include <array>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define mp make_pair
#define lowb lower_bound
#define upb upper_bound
#define bins binary_search
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define all(_x) (_x).begin(),(_x).end()
#define sqr(_x) ((_x)*(_x))
#define cub(_x) ((_x)*(_x)*(_x))
#define gcd __gcd
#define lcm(_a, _b) ((_a)/gcd(_a,_b)*(_b))
#define forn(_i, _l, _r) for(int _i=_l;_i<_r;++_i)
#define ford(_i, _l, _r) for(int _i=_l;_i>=_r;--_i)
#define sz(_A) (int)_A.size()
#define re return
#define FASTER ios::sync_with_stdio(false);cout.setf(ios::showpoint);\
cin.tie(0);cout.tie(0)
#define F(_i, _l, _r) for(int _i=_l;_i<_r;++_i)
#define f(_i, _n) for(int _i=0;_i<_n;++_i)
#define bcnt __builtin_popcount
#define bcntll __builtin_popcountll
#define bcnt0 __builtin_ctz
#define bcnt0ll __builtin_ctzll
#define ep emplace
#define eb emplace_back
#define islower(c) (c>='a' && c<='z')
#define isupper(c) (c>='A' && c<='Z')
#define isalpha(c) (islower(c) || isupper(c))
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }
typedef unsigned long long ulint;
typedef long long ll;
typedef long double ld;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
const int mod = 1000000007;
typedef unsigned long long ull;
const int inf = INT_MAX;
const lint linf = LLONG_MAX;

template<class X>
inline void getarr(X *a, int n) { for (int i = 0; i < n; i++) cin >> a[i]; }

template<class X>
inline void getarr(X *a, int n, int m) { for (int i = 0; i < n; i++) getarr(a[i], m); }

template<class X>
inline void putarr(X *a, int n, char ch = ' ') { for (int i = 0; i < n; i++) cout << a[i] << ch; }

template<class X>
inline void putarr(X *a, int n, int m) {
    for (int i = 0; i < n; i++) {
        putarr(a[i], m, ' ');
        cout << '\n';
    }
}

template<class X>
inline X abs(X a) { return a < 0 ? -a : a; }

template<class X>
inline void mini(X &x, X y) { x = min(x, y); }

template<class X>
inline void maxi(X &x, X y) { x = max(x, y); }

template<class X, class C=less<X>, class Y=__gnu_pbds::null_type>
using ordered_map=__gnu_pbds::tree<X, Y, C, __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
template<class X, class C=greater<X>> using heap=__gnu_pbds::priority_queue
        <X, C, __gnu_pbds::pairing_heap_tag>;

template<class X>
constexpr X bround(X x) { re x == 0 ? 1 : bround(x >> 1) << 1; }

template<class X=int>
X myrand(X l = 0, X r = inf) {
    static mt19937 gen;
    uniform_int_distribution<X> dist(l, r);
    return dist(gen);
}

//--------------------------------------------------stdfunc------------------
int a[2500];
int main() {
    FASTER;
#ifdef home
    assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt","w",stdout));
#endif // home
    int n,k;
    cin>>n>>k;
    getarr(a,n);
    sort(a,a+n);
    ll ans=0;
    f(i,k)ans+=a[i];
    cout<<ans;
    return 0;
}