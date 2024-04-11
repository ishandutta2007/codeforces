#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
#define maxn 4194304
using namespace std;

int n; 
int line[maxn];
int ans[maxn];
int two[22];

int main(){
    two[0] = 1;
    rep(i, 1, 21) two[i] = two[i - 1] << 1;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &line[i]), ans[maxn - 1 - line[i]] = line[i];
    rep(i, 0, 21) rep(j, 0, maxn - 1) if (!(j & two[i]) && !ans[j] && ans[j ^ two[i]]) ans[j] = ans[j ^ two[i]];
    rep(i, 1, n) {
        if (ans[line[i]]) printf("%d ", ans[line[i]]);
        else printf("-1 ");
    }
    return 0;
}