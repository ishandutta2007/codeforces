#include <cstdio>
#include <algorithm>
#define g std::__gcd
long long A[555555],B[555555],n,a=0;
int main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&A[i],&B[i]),a=g(a,A[i]*B[i]);
    if(a==1)return puts("-1"),0;
    for(int i=1;i<=n;i++)if(g(a,A[i])>1)a=g(a,A[i]);else a=g(a,B[i]);
    return printf("%lld\n", a), 0;
}