#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 105;
mt19937 rng(time(0));

int T, n, k;
int a[N * N], cnt[N], ans[N][2];

int main() {
    cin >> n >> k;
    rep(i, 1, n * k) scanf("%d", a + i);
    int x = (n - 1) / (k - 1) + 1;

    int idx = 1;
    rep(iter, 1, k - 1) {
        memset(cnt, 0, sizeof cnt);
        int num = 0, last_idx = idx;
        for (; num < x && idx <= n * k; idx++) {
            //cerr << idx << " " << num << " " << x << endl;
            if (a[idx])
                cnt[a[idx]]++;
            if (cnt[a[idx]] == 2)
                num++;
        }
        rep(i, 1, n) if (cnt[i] >= 2) {
            int num = 0;
            rep(j, last_idx, idx) if (a[j] == i) {
                ans[i][num++] = j;
                if (num == 2)
                    break;
            }
            rep(j, idx + 1, n * k) if (a[j] == i) a[j] = 0;
        }
    }

    rep(i, 1, n) cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}