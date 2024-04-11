#include <cstdio>
#include <algorithm>

using namespace std;

long long a,b,c,l;

long long f(long long x) { return (x+2)*(x+1)/2; }

int main() {
    scanf("%lld%lld%lld%lld",&a,&b,&c,&l);
    long long ans = (l+3)*(l+2)*(l+1)/6;
    for (long long r=0;r<=l;r++) {
        long long tot = a+b+c+r;
        if (2*a>=tot || 2*b>=tot || 2*c>=tot) ans-=f(r);
        else {
            long long need = (tot+1)/2-a;
            if (need<=r) ans-=f(r-need);
            need = (tot+1)/2-b;
            if (need<=r) ans-=f(r-need);
            need = (tot+1)/2-c;
            if (need<=r) ans-=f(r-need);
        }
    }
    printf("%lld\n",ans);

    return 0;
}