#include<bits/stdc++.h>

const int inf=2000000000;

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int l=inf,r=-inf,d=inf,u=-inf;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%i%i",&x,&y);
        l=min(l,x);
        r=max(r,x);
        d=min(d,y);
        u=max(u,y);
    }
    long long m=max(r-l,u-d);
    printf("%lli",m*m);
}