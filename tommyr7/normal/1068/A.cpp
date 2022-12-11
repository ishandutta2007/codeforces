#include <bits/stdc++.h>
using namespace std;
long long n,m,k,l;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
    long long ans=(k+l+m-1)/m;
    if (1LL*ans*m>n) printf("%d\n",-1); else printf("%lld\n",ans);
    return 0;
}