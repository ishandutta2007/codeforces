#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=2)
        printf("%d",n),exit(0);
    int a[n];
    scanf("%d%d",&a[0],&a[1]);
    int m=2,t=2;
    for(int i=2;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==a[i-1]+a[i-2])
            t++;
        else
            t=2;
        m=max(m,t);
    }
    printf("%d",m);
}