#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[101], c[101];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

typedef vector<vector<int>> mat;

mat matmul(const mat& a, const mat& b) {
    int n = (int)a.size();
    mat ret(101);
    for (int i = 0; i < n; ++i) ret[i] = vector<int>(101);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
        }
    }
    return ret;
}

mat fpow(mat a, int n) {
    mat ret(101);
    for (int i = 0; i < a.size(); ++i) ret[i] = vector<int>(101), ret[i][i] = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    while (n--) {
        int d; cin >> d;
        ++c[d];
    }
    dp[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= i; ++j) dp[i] = add(dp[i], mul(dp[i - j], c[j]));
    }
    if (x <= 100) {
        int ans = 0;
        for (int i = 0; i <= x; ++i) ans = add(ans, dp[i]);
        cout << ans << endl;
        return 0;
    }
    mat init(101);
    for (int i = 0; i <= 100; ++i) init[i] = vector<int>(101);
    init[0][0] = 1;
    for (int i = 1; i <= 100; ++i) init[i][0] = c[i], init[i][1] = c[i];
    for (int i = 2; i <= 100; ++i) init[i - 1][i] = 1;
    mat m = fpow(init, x - 100);
    int sum = 0;
    for (int i = 0; i <= 100; ++i) sum = add(sum, dp[i]);
    for (int i = 1; i <= 100; ++i) sum = add(sum, mul(dp[100 - i + 1], m[i][0]));
    cout << sum << endl;
    return 0;
}