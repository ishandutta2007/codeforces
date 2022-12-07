#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 16777216
#define LL long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
using namespace std;

int n;
int a[maxn];
int two[24];

int main(){
    //freopen("vowels.in", "r", stdin);
    char s[5];
    two[0] = 1;
    rep(i, 1, 23) two[i] = two[i - 1] << 1;
    scanf("%d", &n);
    /*rep(i, 1, n) {
        LL now = 0;
        scanf("%s", s);
        rep(j, 0, 2) now |= two[(s[j] - 'a')];
        a[maxn - 1 - now]++;
    }
    rep(i, 0, 23) rep(j, 0, maxn - 1) if (!(j & two[i])) a[j] += a[j ^ two[i]];
    LL ans = 0;
    //rep(j, 0, maxn - 1) ans += (n - a[j]);
    rep(j, 0, maxn - 1) ans ^= ((LL)n - a[j]) * (n - a[j]);
    printf("%I64d", ans);*/

    rep(i, 1, n) {
        LL now = 0;
        scanf("%s", s);
        rep(j, 0, 2) now |= two[(s[j] - 'a')];
        a[now]++;
    }
    rep(i, 0, 23) rep(j, 0, maxn - 1) if (j & two[i]) a[j] += a[j ^ two[i]];
    LL ans = 0;
    //rep(j, 0, maxn - 1) ans += (n - a[j]);
    rep(j, 0, maxn - 1) ans ^= ((LL)n - a[j]) * (n - a[j]);
    printf("%I64d", ans);
    return 0;
}