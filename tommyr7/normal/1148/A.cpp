#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if (a==b) printf("%lld\n",a+b+c+c);
    else if (a>b) printf("%lld\n",b+1+b+c+c);
    else printf("%lld\n",a+a+1+c+c);
    return 0;
}