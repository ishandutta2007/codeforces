#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define int long long

using namespace std;

const int N = 57, INF = 15e17, INF0 = 15e8;

int mul(int a, int b) {
    int res = sqrt(a) * sqrt(b);
    if (res > INF0) return INF;
    return min(a * b, INF);
}

int add(int a, int b) {
    return min(a + b, INF);
}

int slog[N][N];
bool used[N];
int dp[N], fact[N];

void init() {
    memset(slog, 0, sizeof(slog));
    for (int i = 1; i < N; i++) {
        slog[i][1] = 1;
        for (int j = 2; j <= i; j++) {
            for (int last = 1; last < i; last++) {
                slog[i][j] = add(slog[i][j], slog[i - last][j - 1]);
            }
        }
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (i > 1) dp[i] = add(dp[i], dp[i - 2]);
        for (int last = 3; last <= i; last++) {
            int cur = mul(fact[last - 2], dp[i - last]);
            dp[i] = add(dp[i], cur);
        }
    }
}

vector <int> solve_one(int n, int k) {
    memset(used, 0, sizeof(used));
    vector <int> res(n + 1);
    res[1] = n;
    used[n] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (used[j]) continue;
            res[i] = j;
            int cur = j;
            bool good = 1;
            while (cur <= i) {
                cur = res[cur];
                if (cur == j) {
                    good = 0;
                    break;
                }
            }
            if (!good) continue;
            int rest = n - i;
            int cnt = (rest > 1 ? fact[rest - 1] : 1);
            if (k >= cnt) k -= cnt;
            else break;
        }
        used[res[i]] = 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (dp[n] < k) {
        cout << -1 << endl;
        return;
    }
    k--;
    vector <int> ans;
    int add = 0;
    while (n > 0) {
        int len = -1;
        for (int i = 1; i <= n; i++) {
            int left = (i > 1 ? fact[i - 2] : 1);
            int cnt = mul(left, dp[n - i]);
            if (k >= cnt) k -= cnt;
            else {
                len = i;
                break;
            }
        }
        int k1 = k / dp[n - len], k2 = k % dp[n - len];
        vector <int> kek = solve_one(len, k1);
        k = k2;
        for (int i = 1; i <= len; i++) {
            ans.push_back(kek[i] + add);
        }
        add += len;
        n -= len;
    }
    for (int elem : ans) cout << elem << ' ';
    cout << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}