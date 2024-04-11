#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int m=min(a,b),ans=1;
    for(int i=2;i<=m;i++)
        ans*=i;
    printf("%d",ans);
}