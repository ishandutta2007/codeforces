#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        long long l,r;
        scanf("%llu%llu",&l,&r);
        for(int j=0;(l|((long long)1<<j))<=r;j++)
            /*printf("%llu\n",*/l|=(long long)1<<j;
        printf("%llu\n",l);
    }
}