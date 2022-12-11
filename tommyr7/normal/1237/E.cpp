#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    int now=1,tmp=1;
    while (now<n)
    {
        if (tmp%2==1) ++now;
        else if (now%2==0) now*=2;
        else now=2*now-1;
        ++tmp;
    }
    if (n==now) printf("%d\n",1); else printf("%d\n",0);
    return 0;
}