#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int m=2e9;
    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        m=min(m,a[i]+=p);
    }
    int add=l-m;
    m=0;
    for(int i=0;i<n;i++)
        m=max(m,a[i]+=add);
    if(m>r)
        printf("-1");
    else
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
}