#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define INF 2000000005
#define maxn 1000005
using namespace std;
int pre[maxn];
int suf[maxn];
int n, k;
int line[maxn];

int main(){
    scanf("%d%d", &n, &k);
    int maxnum = -INF, minnum = INF;
    for (int i = 1; i <= n; i++) scanf("%d", &line[i]), maxnum = max(maxnum, line[i]), minnum = min(minnum, line[i]);
    if (k >= 3) printf("%d", maxnum);
    else if (k == 2){
        if (line[1] == maxnum || line[n] == maxnum) printf("%d", maxnum);
        else {
            pre[0] = INF;
            suf[n + 1] = INF;
            for (int i = 1; i <= n; i++) pre[i] = min(pre[i - 1], line[i]);
            for (int i = n; i >= 1; i--) suf[i] = min(suf[i + 1], line[i]);
            int ans = -INF;
            for (int i = 1; i <= n - 1; i++){
                ans = max(ans, max(pre[i], suf[i + 1]));
            }
            printf("%d", ans);
        }
    }
    else printf("%d", minnum);
    return 0;
}