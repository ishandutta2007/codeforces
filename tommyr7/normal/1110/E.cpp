#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int c[Maxn],t[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    if (c[1]!=t[1]) 
    {
        printf("No\n");
        return 0;
    }
    if (c[n]!=t[n])
    {
        printf("No\n");
        return 0;
    }
    for (int i=1;i<n;i++)
    {
        c[i]=c[i+1]-c[i];
        t[i]=t[i+1]-t[i];
    }
    sort(c+1,c+n);
    sort(t+1,t+n);
    for (int i=1;i<n;i++)
        if (c[i]!=t[i])
        {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}