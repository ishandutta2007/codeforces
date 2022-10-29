#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, k;
LL a[N], s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        rep(i, n - k + 1, n) cin >> s[i];
        if (k == 1) {
            cout << "Yes\n";
            continue;
        }
        bool flag = true;
        rep(i, n - k + 2, n) {
            a[i] = s[i] - s[i - 1];
            if (i > n - k + 2 && a[i] < a[i - 1])
                flag = false;
        }
        if (a[n - k + 2] * (n - k + 1) < s[n - k + 1])
            flag = false;
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}