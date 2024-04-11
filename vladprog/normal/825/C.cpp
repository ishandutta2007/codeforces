#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int p=0;
    for(int i=0;i<n;i++)
    {
        while(k*2<a[i])
            k*=2,p++;
        k=max(k,a[i]);
    }
    printf("%d",p);
}