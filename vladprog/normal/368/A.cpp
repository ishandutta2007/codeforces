#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int m;
    scanf("%d",&m);
    int s=0;
    for(int i=0;i<min(n,m);i++)
        s+=a[i];
    s-=d*(m-min(n,m));
    printf("%d",s);
}