#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, m, k, x;
int ans[N], cnt[N];
vector<int> a[N];

int main() {
    cin >> T;
    rep(cas, 1, T) {
        scanf("%d%d", &n, &m);

        rep(i, 1, max(m, n)) a[i].clear();
        rep(i, 1, max(m, n)) ans[i] = cnt[i] = 0;
        rep(i, 1, m) {
            scanf("%d", &k);
            rep(j, 1, k) scanf("%d", &x), a[i].PB(x);
        }

        rep(i, 1, m) if (a[i].size() == 1) ans[i] = a[i][0], cnt[ans[i]]++;
        bool flag = true;
        rep(i, 1, n) if (cnt[i] > (m + 1) / 2) flag = false;

        if (!flag) {
            printf("NO\n");
        } else {
            printf("YES\n");
            int maxi = 1;
            rep(i, 1, n) if (cnt[i] > cnt[maxi]) maxi = i;
            rep(i, 1, m) if (a[i].size() > 1) {
                for (auto x : a[i])
                    if (x != maxi) {
                        ans[i] = x;
                        cnt[x]++;
                        if (cnt[x] > cnt[maxi])
                            maxi = x;
                        break;
                    }
            }
            rep(i, 1, m) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}