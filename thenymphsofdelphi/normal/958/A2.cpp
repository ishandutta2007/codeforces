#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;

char a[N][N], b[N][N];
int row[N], col[N], n, m;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        int val = 0;
        for (int j = i; j <= i + m - 1; j++){
            for (int k = 1; k <= m; k++){
                val = (val * 26 + a[j][k] - 'a' + 1) % mod;
            }
        }
        row[i] = val;
    }
    for (int i = 1; i <= n - m + 1; i++){
        int val = 0;
        for (int j = 1; j <= m; j++){
            for (int k = i; k <= i + m - 1; k++){
                val = (val * 26 + b[j][k] - 'a' + 1) % mod;
            }
        }
        col[i] = val;
    }
    for (int i = 1; i <= n - m + 1; i++){
        for (int j = 1; j <= n - m + 1; j++){
            if (row[i] == col[j]){
                cout << i << " " << j;
                return 0;
            }
        }
    }
    return 0;
}