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

#define int int16_t

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

const int N = 666;
vector <pii> rgr[N * 10][N];
int dst[N * 10][N];

void bfs(int sum) {
    queue <pii> q;
    q.push({sum, 0});
    dst[sum][0] = 0;
    while (sz(q)) {
        int s = q.front().f, r = q.front().s;
        q.pop();
        for (auto u : rgr[s][r]) {
            if (dst[u.f][u.s] == -1) {
                dst[u.f][u.s] = dst[s][r] + 1;
                q.push({u.f, u.s});
            }
        }
    }
}

void $main() {
    int d, s;
    cin >> d >> s;
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                rgr[i + k][(j * 10 + k) % d].add({i, j});
            }
        }
    }
    for (int i = 0; i < N * 10; i++) {
        for (int j = 0; j < N; j++) {
            dst[i][j] = -1;
        }
    }
    bfs(s);
    int len = dst[0][0];
    if (len == -1) {
        cout << -1;
        return;
    }
    vector <int> ans;
    int csum = 0, cmod = 0;
    for (int i = 0; i < len; i++) {
        int dig = -1;
        for (int j = 0; j < 10; j++) {
            if (dst[csum + j][(cmod * 10 + j) % d] + 1 == dst[csum][cmod]) {
                dig = j;
                break;
            }
        }
        assert(dig != -1);
        csum += dig;
        cmod = (cmod * 10 + dig) % d;
        ans.add(dig);
    }
    for (int i : ans) {
        cout << i;
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