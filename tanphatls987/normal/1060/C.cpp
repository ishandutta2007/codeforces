#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int inf = 1e9 + 10;

int n[2], a[2][N], psum[2][N];
int b[2][N];
int main() {
    cin >> n[0] >> n[1];
    for(int j = 0; j <= 1; j++) {
        for(int i = 1; i <= n[j]; i++) {
            cin >> a[j][i];
            psum[j][i] = psum[j][i - 1] + a[j][i];
        }
        fill(b[j] + 1, b[j] + n[j] + 1, inf);
        for(int L = 1; L <= n[j]; L++)
            for(int R = L; R <= n[j]; R++) 
                b[j][R - L + 1] = min(b[j][R - L + 1], psum[j][R] - psum[j][L - 1]);
    }
    int lim;
    cin >> lim;
    int ans = 0;
    for(int i = 1, j = n[1]; i <= n[0]; i++) {
        while (1LL * b[0][i] * b[1][j] > lim) j--;
        ans = max(ans, i * j);
    }
    cout << ans;
}