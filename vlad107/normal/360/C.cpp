#include <stdio.h>
#include <iostream>

#define INF 1000000000
#define BASE 1000000007
#define N 2222

using namespace std;

int n, k;
string s;
long long f[N][N], g[N][N], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    cin >> s;
    f[0][0] = 1;
    g[0][0] = 1;
    ans = f[0][k];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j] = (g[i - 1][j] * (s[i - 1] - 'a')) % BASE;
            for (int x = 1; ((x <= i) && (x * (n - i + 1) <= j)); x++)
                f[i][j] = (f[i][j] + f[i - x][j - x * (n - i + 1)] * (26 - (s[i - 1] - 'a' + 1))) % BASE;
            g[i][j] = (g[i - 1][j] + f[i][j]) % BASE;
        }
        ans = (ans + f[i][k]) % BASE;
    }
    cout << ans << endl;
}