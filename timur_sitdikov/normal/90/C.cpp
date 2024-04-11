#include <stdio.h>

int main()
{
    long long n, m, k, min, v[10001], i, ans, p;
    scanf("%lld %lld %lld", &n, &m, &k);
    if (!(n&1)) {printf("0"); return 0;}
    for(i=0; i<n;i++)
        scanf("%lld", &v[i]);
    min=v[0];
    for(i=2; i<n; i+=2)
        if (v[i]<min) min=v[i];
    if (m<(n+1)/2) {printf("0"); return 0;} 
    p=m/((n+1)/2);
    ans=(k*p<min? k*p: min);
    printf("%lld", ans);
}