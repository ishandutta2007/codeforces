#include <cstdio>
#include <algorithm>

using namespace std;

long long n,k;
int l,MOD;

int binpow(int a, long long p) {
    int ans = 1;
    int cur = a;
    for (int i=0;i<60;i++) {
        if (p&(1LL<<i)) ans = ((long long) ans*cur)%MOD;
        cur = ((long long) cur*cur)%MOD;
    }
    return ans;
}

int fib(long long g) {
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i=60;i>=0;i--) {
        int f = ((long long) b*b+(long long) c*c)%MOD;
        int e = ((long long) a*b+(long long) b*c)%MOD;
        a = ((long long) a*a+(long long) b*b)%MOD;
        b = e; c = f;
        if (g&(1LL<<i)) {
            if (!a) a = b = 1;
            else {
                int d = (a+b)%MOD;
                c = b; b = a; a = d;
            }
        }
    }
    return b;
}

int main() {
    scanf("%I64d%I64d%d%d",&n,&k,&l,&MOD);
    if (l<63 && k>=(1LL<<l)) return printf("0\n"), 0;
    int no = fib(n+2);
    int has = (binpow(2,n)-no+MOD)%MOD;
    int ans = 1;
    for (int i=0;i<l;i++) {
        if (i<63 && k&(1LL<<i)) ans = ((long long) ans*has)%MOD;
        else ans = ((long long) ans*no)%MOD;
    }
    printf("%d\n",ans%MOD);

    return 0;
}