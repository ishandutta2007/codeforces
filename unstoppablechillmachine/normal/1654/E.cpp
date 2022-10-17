#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const int N = 1e5 + 10;
const int B = 500;
const int MX = 30000010;
int sum[2 * MX];
int sum2[2000010];
int x[N];

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    int answer = 0;
    for (int delta = -B / 2; delta <= B / 2; delta++) {
        for (int i = 1; i <= n; i++) {
            answer = max(answer, ++sum[MX + x[i] - delta * i]);
        }
        for (int i = 1; i <= n; i++) {
            sum[MX + x[i] - delta * i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = max(i - 400, 1); j <= min(i + 400, n); j++) {
            if (i == j) continue;
            int delta = (x[i] - x[j]) / (i - j);
            if (delta * (i - j) == x[i] - x[j]) {
                answer = max(answer, ++sum2[delta + 1000000] + 1);
            }
        }
        for (int j = max(i - 400, 1); j <= min(i + 400, n); j++) {
            if (i == j) continue;
            int delta = (x[i] - x[j]) / (i - j);
            sum2[delta + 1000000] = 0;
        }
    }
    cout << n - answer << '\n';
}