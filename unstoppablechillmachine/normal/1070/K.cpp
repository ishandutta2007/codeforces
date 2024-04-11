//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#ifdef flaax
template <class H> void _dbg(const char* s, H h) { cerr << s << " = " << h << endl; }
template <class H, class... T> void _dbg(const char* s, H h, T... t) {
    while (*s != ',') cerr << *s++; cerr << " = " << h << ","; _dbg(s + 1, t...);
}
#define db(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define add push_back
#define del pop_back
#define ins insert
#define ers erase
#define f first
#define s second
ll sqr(ll x) { return x * x; }
ld sqrd(ld x) { return x * x; }
#define pw(x) (1ll << (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937 Random((int)time(0));
ll rnd(ll x) { return Random() % x; }
#define TASK ""

const ll INF = (ll)1e9 + 282;
const ll MOD = (ll)1e9 + 7;
const ld PI = acosl(-1.0);

const int N = 2e5 + 10;
int arr[N];

void $main() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % k != 0) {
        cout << "No";
        return;
    }
    ll need = sum / k, cur = 0, curcnt = 0;
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        cur += arr[i];
        curcnt++;
        if (cur == need) {
            ans.add(curcnt);
            cur = 0;
            curcnt = 0;
        }
    }
    if (cur || sz(ans) != k) {
        cout << "No";
        return;
    }
    cout << "Yes" << endl;
    for (int i : ans) {
        cout << i << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(12);
#ifdef flaax
    assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
#else
    //assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    //assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
#endif
    $main();
#ifdef flaax
    cout << endl;
    cerr << endl << "\t" << fixed << setprecision(12) << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}