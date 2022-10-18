#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, K = 55;

int dp[2][N][K][K], n, p, m, lim, ans = 0;
bool a[N], b[N];

int main(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d%d%d", &n, &p, &m);
    int num, x;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        scanf("%d", &x);
        a[x] = 1;
    }
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        scanf("%d", &x);
        b[x] = 2;
    }
    if (n % m == 0){
    	lim = n / m;
    }
    else{
    	lim = n / m + 1;
    }
    if (p >= 2 * lim){
        for (int i = 1; i <= n; i++){
        	if (a[i] || b[i]){
        		ans++;
        	}
		}
        cout << ans;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    int lst = 0, now = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= p; j++){
            for (int k = 0; k < m; k++){
                for (int l = 0; l < m; l++){
                    dp[now][j][k][l] = -1;
                }
            }
        }
        for (int j = 0; j <= p; j++){
            for (int k = 0; k < m; k++){
                for (int l = 0; l < m; l++){
                    if (dp[lst][j][k][l] != -1){
                        bool cka = false, ckb = false;
                        if (a[i]){
							cka = true;
						}
                        if (b[i]){
							ckb = true;
						}
                        if (!k){
							cka = false;
						}
                        if (!l){
							ckb = false;
						}
                        dp[now][j][max(k - 1, 0)][max(l - 1, 0)] = max(dp[now][j][max(k - 1, 0)][max(l - 1, 0)], dp[lst][j][k][l] + max(cka, ckb));
                        if (j < p){
                            if (!k){
								dp[now][j + 1][m - 1][max(l - 1, 0)] = max(dp[now][j + 1][m - 1][max(l - 1, 0)], dp[lst][j][k][l] + a[i]);
							}
                            if (!l){
								dp[now][j + 1][max(k - 1, 0)][m - 1] = max(dp[now][j + 1][max(k - 1, 0)][m - 1], dp[lst][j][k][l] + b[i]);
							}
                        }
                    }
                }
            }
        }
        lst ^= 1;
        now ^= 1;
    }
    for (int j = 0; j <= p; j++){
        for (int k = 0; k < m; k++){
            for (int l = 0; l < m; l++){
                ans = max(ans, dp[lst][j][k][l]);
            }
        }
    }
    cout << ans;
}