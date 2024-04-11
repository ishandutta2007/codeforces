#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],s[n*2];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        s[i]=a[i];
        s[n+i]=b[i];
    }
    sort(s,s+n*2);
    for(int i=0;i<n;i++)
        if(i<=n/2-1||a[i]<=s[n-1])
            printf("1");
        else
            printf("0");
    printf("\n");
    for(int i=0;i<n;i++)
        if(i<=n/2-1||b[i]<=s[n-1])
            printf("1");
        else
            printf("0");
    printf("\n");
}