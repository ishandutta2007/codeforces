#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 205;
mt19937 rng(time(0));

int T, n, m, k, cnt[30];
char s[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> (s + 1);
        memset(cnt, 0, sizeof cnt);
        rep(i, 1, n) cnt[s[i] - 'a']++;
        int idx = 0;
        rrep(i, k, 1) {
            while (cnt[idx] >= i)
                idx++;
            ans[i] = 'a' + min(idx, n / k);
        }
        ans[k + 1] = 0;
        cout << (ans + 1) << "\n";
    }
    return 0;
}