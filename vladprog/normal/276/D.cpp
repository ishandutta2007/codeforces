#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long l,r;
    scanf("%I64d%I64d",&l,&r);
    long long a=l^r;
    long long one=0;
    for(int i=63;i>=0;i--)
    {
        one=one||((1ll<<i)&a);
        a|=one<<i;
        //printf("%I64d",&one);
    }
    printf("%I64d",a);
}