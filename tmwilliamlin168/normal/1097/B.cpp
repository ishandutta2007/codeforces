#include<bits/stdc++.h>
using namespace std;
int i,n,m,s,a[19];
int main()
{
    for(scanf("%d",&n); i<n; scanf("%d",a+i),++i);
    for(m=1<<n; m--;)
    {
        for(s=0,i=n; i--; ((1<<i)&m)?s+=a[i]:s-=a[i]);
        if(!(s%360))
            printf("YES\n"),exit(0);
    }
    printf("NO\n"),exit(0);
}