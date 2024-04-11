#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define M 1000000007
#define maxn 1048576
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
using namespace std;
int n;
int a[maxn];
int two[maxn];
int main(){
    //freopen("jzz.in", "r", stdin);
    //freopen("jzz.out", "w", stdout);
    int x;
    two[0] = 1;
    rep(i, 1, maxn - 1) two[i] = (two[i - 1] << 1) % M;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &x), a[x]++;
    rep(i, 0, 19) rep(j, 0, maxn - 1) if (!(j & two[i])) a[j] += a[j ^ two[i]];
    rep(j, 0, maxn - 1) a[j] = (M + two[a[j]] - 1) % M;
    rep(i, 0, 19) rep(j, 0, maxn - 1) if (!(j & two[i])) a[j] = (M + a[j] - a[j ^ two[i]]) % M;
    printf("%d", a[0]);
    return 0;
}