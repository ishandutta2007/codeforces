#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
int step[N][N];
int f[N][N];
long long psum[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) psum[i] = psum[i - 1] + a[i]; 
    
    for(int i = n; i >= 1; i--){
        for(int j = i, nj = i; j <= n; j++){
            while (nj <= n && psum[nj] - psum[j] < psum[j] - psum[i - 1])
                nj++;  
            step[i][j] = nj;
        }
    }
    for(int i = 1; i <= n; i++)
        fill(f[i] + 1, f[i] + n + 1, n + 1);

    for(int i = 1; i <= n; i++) {
        f[1][i] = min(f[1][i], i - 1);
        for(int j = 1; j <= i; j++){
            int ni = step[j][i];
            f[i + 1][ni] = min(f[i + 1][ni], f[j][i] + (ni - i - 1));
            f[j][i + 1] = min(f[j][i + 1], f[j][i] + 1);
        }
    }
    int ans = n + 1;
    for(int i = 1; i <= n; i++) ans = min(ans , f[i][n]);
    cout << ans;
}