#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
void add(int &x, int y) {
    x += y;   
    if (x >= m) x -= m;
}
int s[4000010], dp[4000010];

int main() {
    scanf("%d%d",&n,&m);
    int S = 1;
    for (int i = 1; i <= n; i++) {
        add(S, s[i]);
        dp[i] = S;
        //printf("dp[%d] = %d\n",i,dp[i]);
        for (int j = 2 * i; j <= n; j += i) {
            int R = (j / i) * (i + 1);
            //printf("add %d %d\n",j,R);
            add(s[j], dp[i]);
            if (R <= n) add(s[R], m - dp[i]);
        }
        if (i > 1) add(S, dp[i]);
    }
    printf("%d\n",dp[n]);
}