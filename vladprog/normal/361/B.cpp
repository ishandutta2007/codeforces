#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==k)
        printf("-1"),exit(0);
    for(int i=2;i<=n-k;i++)
        printf("%d ",i);
    printf("1 ");
    for(int i=n-k+1;i<=n;i++)
        printf("%d ",i);
}