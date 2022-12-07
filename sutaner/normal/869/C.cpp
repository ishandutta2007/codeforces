#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define maxn 5005
#define LL long long int
#define M 998244353
using namespace std;

LL fac[maxn];
LL ifac[maxn];
LL inv[maxn];
void init(){
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % M;
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) inv[i] = M - inv[M % i] * (M / i) % M;
    ifac[0] = 1;
    for (int i = 1; i < maxn; i++) ifac[i] = ifac[i - 1] * inv[i] % M;
}

LL cal(int m, int n){
    return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

LL work(int a, int b){
    LL ans = 0;
    for (int i = 0; i <= min(a, b); i++){
        ans += cal(b, i) * fac[a] % M * ifac[a - i] % M;
        ans %= M;
    }
    return ans;
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    init();
    LL ans = 1;
    ans = ans * work(a, b) % M * work(a, c) % M * work(b, c) % M;
    printf("%I64d", ans);
    return 0;
}