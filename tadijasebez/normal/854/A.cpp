#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    int sol=-1;
    scanf("%i",&n);
    for(i=1;i<(n+1)/2;i++)
    {
        if(__gcd(i,n-i)==1) sol=i;
    }
    if(sol==-1) printf("-1\n");
    else printf("%i %i\n",sol,n-sol);
    return 0;
}