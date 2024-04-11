#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#include <numeric>
using namespace std;
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)
using ll = long long;
constexpr int inf = 1e9 + 7;
constexpr ll longinf = 1LL << 60;
constexpr ll mod = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<ll> a(n1), b(n2), c(n3), d(n4);
    rep(i, n1) cin >> a[i];
    rep(i, n2) cin >> b[i];
    rep(i, n3) cin >> c[i];
    rep(i, n4) cin >> d[i];
    auto solve = [&](vector<ll> &pre, vector<ll> &cur) -> vector<ll> {
        int m;
        cin >> m;
        set<pair<int, int> > st;
        rep(i, m){
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            st.insert({x, y});
        }
        int a = pre.size(), b = cur.size();
        vector<int> ord(a);
        rep(i, a) ord[i] = i;
        sort(ord.begin(), ord.end(), [&](int x, int y) {
            return pre[x] < pre[y];
        });
        vector<ll> ret(b);
        rep(i, b) {
            int j = 0;
            while (j < a && st.count({ord[j], i})) ++j;
            ret[i] = j < a ? pre[ord[j]] + cur[i] : inf;
        }
        return ret;
    };
    auto ret1 = solve(a, b);
    auto ret2 = solve(ret1, c);
    auto ret3 = solve(ret2, d);
    ll ans = *min_element(ret3.begin(), ret3.end());
    cout << (ans < inf ? ans : -1) << endl;
    return 0;
}