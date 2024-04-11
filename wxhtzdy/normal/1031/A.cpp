#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ans=0;
    while(k--)
    {
        ans+=2*n+2*m-4;
        n-=4;
        m-=4;
    }
    printf("%d",ans);
}