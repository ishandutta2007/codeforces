#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 4e5 + 5;
mt19937 rng(time(0));

int q, u, v;

int main() {
    cin >> q;
    rep(i, 1, q) {
        scanf("%d%d", &u, &v);
        int cnt1 = 0, cnt2 = 0;
        bool flag = u <= v;
        rep(j, 0, 30) {
            cnt1 += (u >> j & 1);
            cnt2 += (v >> j & 1);
            if (cnt1 < cnt2)
                flag = false;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}