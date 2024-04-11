#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
      printf("%lld ",a[i]+a[i+1]);
    return 0;
}