#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 20;
const int MOD = 1e9 + 7;

int n;
int a[N];
int com[N][N];
int f[N][N];
int use4[N];
int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n - 3; i++) {
        int val = 0;
        for(int j = 0; j < 4; j++) val = val * 2 + a[i + j];
        if (val == 3) continue;
        if (val == 5) continue;
        if (val == 14) continue;
        if (val == 15) continue;

        use4[i] = 1;
    }
    //for(int i = 1; i <= n; i++) cout << use4[i] << " ";
    cout << endl;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if (a[i] == a[j]) {
            com[i][j] = com[i - 1][j - 1] + 1;
        }
    long long ans = 0;

    for(int R = 1; R <= n; R++) {
        int re = 0;
        for(int L = 1; L < R; L++)
            re = max(re, com[L][R]);

        f[R + 1][R] = 1;
        for(int L = R; L >= 1; L--) {
            for(int i = 1; i <= 3; i++)     
                f[L][R] = (f[L][R] + f[L + i][R]) % MOD;
            if (use4[L])
                f[L][R] = (f[L][R] + f[L + 4][R]) % MOD;
            if (R - L + 1 > re)
                ans = (ans + f[L][R]) % MOD;
        }
        cout << ans << '\n';
    }
}