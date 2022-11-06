#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
int dp[maxn][maxn];
bool v[maxn][maxn];

int go(int a, int b) {
    if (a == b && b == 0) return 0;
    if (v[a][b]) return dp[a][b];
    v[a][b] = true;
    for (int i = 1; i <= a; ++i) if (go(a - i, b) == 0) return dp[a][b] = 1;
    for (int i = 1; i <= b; ++i) if (go(a, b - i) == 0) return dp[a][b] = 1;
    for (int i = 1; i <= min(a, b); ++i) {
        if (go(a - i, b - i) == 0) return dp[a][b] = 1;
    }
    return dp[a][b] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b, c; cin >> n;
    if (n == 1) {
        cin >> a;
        if (a) cout << "BitLGM" << endl;
        else cout << "BitAryo" << endl;
    }
    if (n == 2) {
        cin >> a >> b;
        if (go(a, b)) cout << "BitLGM" << endl;
        else cout << "BitAryo" << endl;
    }
    if (n == 3) {
        cin >> a >> b >> c;
        if (a ^ b ^ c) cout << "BitLGM" << endl;
        else cout << "BitAryo" << endl;
    }
    return 0;
}