#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

char s[maxn];
int pre[maxn][3];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("215A.in", "r", stdin);
    #endif
    int q, x, y, n;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    rep(i, 1, n) {
        rep(j, 0, 2) pre[i][j] = pre[i - 1][j];
        pre[i][s[i] - 'x']++;
    }
    scanf("%d", &q);
    rep(i, 1, q){
        scanf("%d%d", &x, &y);
        if (y - x + 1 <= 2) {
            printf("YES\n");
            continue;
        }
        int mx = -1, mi = n + 1;
        rep(i, 0, 2) mx = max(mx, pre[y][i] - pre[x - 1][i]), 
        mi = min(mi, pre[y][i] - pre[x - 1][i]);
        if (mx - mi > 1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}