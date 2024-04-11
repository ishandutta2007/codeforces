#include<bits/stdc++.h>

using namespace std;

const long long z=0;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    long long ans=0;
    for(int i=0;i<5;i++)
        ans+=((n+5-i)/5)*((m+5-(5-i)%5)/5);
    ans-=n/5+1;
    ans-=m/5+1;
    ans++;
    printf("%I64d",ans);
}