#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            if(a[j]>a[j+1])
                printf("%d %d\n",j,j+1),swap(a[j],a[j+1]);
}