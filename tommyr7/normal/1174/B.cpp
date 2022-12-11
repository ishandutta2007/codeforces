#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,a[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool check=true;
    for (int i=2;i<=n;i++)
        if (a[i]%2!=a[1]%2) check=false;
    if (!check) sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}