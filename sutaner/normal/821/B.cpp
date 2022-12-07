#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define LL long long int
using namespace std;
LL m, b;
LL ans = 0;
int main(){
    /*freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);*/
    scanf("%I64d%I64d", &m, &b);
    LL y;
    for (LL x = 0; x <= m * b; x++){
        if (x % m == 0) y = b - x / m;
        else y = b - x / m - 1;
        ans = max(ans, ((LL)(x + 1) * (y + 1) * y >> 1) + ((LL)(y + 1) * (x + 1) * x >> 1));
    }
    printf("%I64d", ans);
    return 0;
}