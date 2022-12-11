#include<bits/stdc++.h>

typedef long long ll;
const int N = 1000010;
typedef std::pair <int, int> pii;
typedef std::pair <int, pii> piii;
const int M = 1010;
const int moder = 998244353;

piii p[N];
int inv[N];
int a[M][M];
int dp[M][M];

void init(){
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
}

int main(){
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            p[i * m + j] = {a[i][j], {i, j}};
        }
    }
    std::sort(p, p + n * m);
    int x2 = 0, y2 = 0, x1 = 0, y1 = 0, sum = 0, cnt = 0;
    for (int i = 0, j; i < n * m; i = j){
        j = i;
        while (j < n * m && p[j].first == p[i].first){
            ++ j;
        }
        if (cnt){
            for (int k = i; k < j; ++ k){
                int x = p[k].second.first, y = p[k].second.second;
                dp[x][y] = (1ll * x * x + 1ll * y * y) % moder * cnt % moder;
                dp[x][y] = (dp[x][y] - 2ll * x1 * x - 2ll * y1 * y) % moder;
                dp[x][y] = ((ll) dp[x][y] + x2 + y2 + sum) % moder;
                dp[x][y] += dp[x][y] < 0 ? moder : 0;
                dp[x][y] = 1ll * dp[x][y] * inv[cnt] % moder; 
            }
        }
        for (int k = i; k < j; ++ k){
            int x = p[k].second.first, y = p[k].second.second;
            x2 = (x2 + 1ll * x * x) % moder;
            y2 = (y2 + 1ll * y * y) % moder;
            x1 += x;
            x1 -= x1 >= moder ? moder : 0;
            y1 += y;
            y1 -= y1 >= moder ? moder : 0;
            ++ cnt;
            sum += dp[x][y];
            sum -= sum >= moder ? moder : 0;
        }
    }
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d\n", dp[r - 1][c - 1]);
    return 0;
}