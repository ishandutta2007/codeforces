#include <iostream>

using namespace std;

long long M = 1e9 + 7;

struct g_x_y{
    long long g, x, y;
    g_x_y() {};
    g_x_y(long long g, long long x, long long y) {
        this->g = g;
        this->x = x;
        this->y = y;
    }
};

g_x_y gcd_x_y(long long a, long long b) {
    if (b == 0) return g_x_y(a, 1, 0);
    g_x_y now = gcd_x_y(b, a % b);
    return g_x_y(now.g, now.y, now.x - now.y * (a / b));
}

long long other(long long x, long long m) {
    g_x_y now = gcd_x_y(x, m);
    if (now.g != 1) {
        return -1;
    }
    if (now.x < 0) now.x += m;
    return now.x;
}

long long find_ans(long long P, long long Q) {
    return (P * other(Q, M)) % M;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    long long s1[n], s2[n];
    for (int i = 0; i < n; i++) {
        cin >> s1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s2[i];
    }
    long long vars_1[n + 1], vars_2[n + 1];
    vars_1[n] = vars_2[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        vars_1[i] = vars_1[i + 1];
        if (s1[i] == 0) {
            vars_1[i] = (vars_1[i] * m) % M;
        }
        vars_2[i] = vars_2[i + 1];
        if (s2[i] == 0) {
            vars_2[i] = (vars_2[i] * m) % M;
        }
    }
    long long P = 0, Q = (vars_1[0] * vars_2[0]) % M;
    long long dp[n + 1];
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s1[i] != 0 && s2[i] != 0) {
            if (s1[i] == s2[i]) dp[i] = dp[i + 1];
            if (s1[i] > s2[i]) dp[i] = (vars_1[i] * vars_2[i]) % M;
            if (s1[i] < s2[i]) dp[i] = 0;
            continue;
        }
        if (s1[i] == 0 && s2[i] == 0) {
            dp[i] = ((m * (m - 1)) / 2) % M;
            dp[i] = (dp[i] * vars_1[i + 1]) % M;
            dp[i] = (dp[i] * vars_2[i + 1]) % M;
            dp[i] = (dp[i] + m * dp[i + 1]) % M;
            continue;
        }
        if (s1[i] == 0) {
            dp[i] = ((m - s2[i]) * vars_1[i + 1]) % M;
            dp[i] = (dp[i] * vars_2[i + 1]) % M;
            dp[i] = (dp[i] + dp[i + 1]) % M;
        }
        if (s2[i] == 0) {
            dp[i] = ((s1[i] - 1) * vars_1[i + 1]) % M;
            dp[i] = (dp[i] * vars_2[i + 1]) % M;
            dp[i] = (dp[i] + dp[i + 1]) % M;
        }
    }
    P = dp[0];
    //cout << P << endl;
    cout << find_ans(P, Q) << endl;
    return 0;
}