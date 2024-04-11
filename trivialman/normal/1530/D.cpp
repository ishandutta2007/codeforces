#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = (1 << 30) - 1;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n;
int a[N], b[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        set<int> remain;
        rep(i, 1, n) scanf("%d", a + i), remain.insert(i), b[i] = 0;

        int ans = 0;
        rep(i, 1, n) if (remain.count(a[i])) b[i] = a[i], remain.erase(a[i]), ans++;

        rep(i, 1, n) if (!b[i]) {
            if (remain.size() > 1) {
                auto iter = remain.begin();
                if (*iter != i)
                    b[i] = *iter;
                else
                    iter++, b[i] = *iter;
                remain.erase(iter);
            } else {
                b[i] = *remain.begin();
                if (b[i] == i) {
                    rep(j, 1, n) if (a[i] == a[j] && j != i) {
                        swap(b[i], b[j]);
                        break;
                    }
                }
            }
        }

        printf("%d\n", ans);
        rep(i, 1, n) printf("%d ", b[i]);
        printf("\n");
    }
    return 0;
}