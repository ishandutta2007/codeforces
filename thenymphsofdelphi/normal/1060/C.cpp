#include<bits/stdc++.h>
using namespace std;

int n, m;
long long x;
long long a[2005], b[2005];
int f[4000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    cin >> x;
    for (int l = 1; l <= n; l++){
        for (int r = l; r <= n; r++){
            f[a[r] - a[l - 1]] = max(f[a[r] - a[l - 1]], r - l + 1);
        }
    }
    for (int i = 1; i <= 4000000; i++){
        f[i] = max(f[i], f[i - 1]);
    }
    int mx = 0;
    for (int l = 1; l <= m; l++){
        for (int r = l; r <= m; r++){
            int cur = b[r] - b[l - 1], gg = x / cur;
            gg = min(gg, 4000000);
            mx = max(mx, (r - l + 1) * f[gg]);
        }
    }
    cout << mx;
}