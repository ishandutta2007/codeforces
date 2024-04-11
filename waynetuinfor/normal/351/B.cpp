#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;
int p[maxn];
double dp[maxn * maxn];

double f(int n) {
    if (n == 0) return 0.0;
    if (n == 1) return 1;
    if (dp[n]) return dp[n];
    if (n >= 2) return dp[n] = 4 + f(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    int pr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (p[j] < p[i]) ++pr;
    }
    // cout << pr << endl;
    cout << fixed << setprecision(20) << f(pr) << endl;
    return 0;
}