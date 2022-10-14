#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define X first
#define Y second

typedef pair < int, int > pii;

const int N = 150;
const int M = 2050;

int t[N], d[N], p[N], ord[N], n;
int dp[N][M];
pii doso[N][M];

bool cmp(int i, int j){
    return d[i] < d[j];
}

vector < int > v;

void rec(int i, int j){
    if(i == 0) return;
    if(doso[i][j].Y != j) v.PB(ord[i - 1]);
    rec(doso[i][j].X, doso[i][j].Y);
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d%d%d", t + i, d + i, p + i);
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    for(int x = 0; x < n;x++){
        int i = ord[x];
        for(int j = 0;j < M;j++){
            if(j + t[i] < d[i]){
                if(dp[x + 1][j + t[i]] < dp[x][j] + p[i]){
                    dp[x + 1][j + t[i]] = dp[x][j] + p[i];
                    doso[x + 1][j + t[i]] = {x, j};
                }
            }
            if(dp[x + 1][j] < dp[x][j]){
                dp[x + 1][j] = dp[x][j];
                doso[x + 1][j] = {x, j};
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < M;i++){
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    for(int i = 0;i < M;i++){
        if(dp[n][i] == ans){
            rec(n, i);
            break;
        }
    }
    printf("%d\n", v.size());
    reverse(v.begin(), v.end());
    for(int i = 0;i < v.size();i++){
        printf("%d ", v[i] + 1);
    }
    return 0;
}