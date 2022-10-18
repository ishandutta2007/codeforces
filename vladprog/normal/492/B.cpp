#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int d=max(a[0],l-a[n-1])*2;
    for(int i=0;i<n-1;i++)
        d=max(d,a[i+1]-a[i]);
    printf("%f",d/2.0);
}