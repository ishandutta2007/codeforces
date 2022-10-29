#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, x[N], y[N], to[N];
struct dat {
    int id, cnt;
} b[N];
vector<LL> a[N], s[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        LL sum = 0;
        rep(i, 1, n) a[i].clear(), s[i].clear();
        rep(i, 1, n) b[i] = {i, 0};
        rep(i, 1, n) scanf("%d", x + i), b[x[i]].cnt++;
        rep(i, 1, n) scanf("%d", y + i), sum += y[i];

        sort(b + 1, b + n + 1, [](dat x, dat y) { return x.cnt > y.cnt; });
        rep(i, 1, n) to[b[i].id] = i;
        rep(i, 1, n) x[i] = to[x[i]];

        rep(i, 1, n) a[x[i]].PB(y[i]), s[x[i]].PB(0);
        //rep(i, 1, n) cerr << a[i].size() << " ";
        //cerr << endl;

        rep(i, 1, n) {
            sort(a[i].begin(), a[i].end());
            int sz = a[i].size();
            if (sz) {
                s[i][0] = a[i][0];
                rep(j, 1, sz - 1) s[i][j] = s[i][j - 1] + a[i][j];
            }
        }

        int last = n;
        rep(i, 1, n) {
            while (last && a[last].size() < i) {
                int sz = a[last].size();
                if (sz)
                    sum -= s[last][sz - 1];
                last--;
            }
            LL sub = 0;
            rep(j, 1, last) {
                int mod = a[j].size() % i;
                sub += mod == 0 ? 0 : s[j][mod - 1];
            }
            printf("%lld ", sum - sub);
        }
        printf("\n");
    }
    return 0;
}