#include <bits/stdc++.h>
using namespace std;
long long x;
int ans=0;
int main()
{
    scanf("%lld",&x);
    for (int i=1;1LL*i*i<=x;i++)
        if (x%i==0)
        {
            ++ans;
            if (1LL*i*i!=x) ++ans;
        }
    printf("%d\n",ans);
    return 0;
}