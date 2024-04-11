#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

const int maxd=100005;
int n,a[maxd],t[maxd],s[maxd],top,i,st;
int readfile()
{
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i+1]);
}
int binsearch(int val,int l,int r)
{
    while (l<=r)
    {
        int m=(l+r)/2;
        if (val>=a[s[m]]) l=m+1;else r=m-1;
    }
    return l;
}
int solve()
{
    a[0]=0;a[n+1]=maxd;
    s[1]=0;top=1;
    for(i=1;i<=n+1;i++)
    {
        st=binsearch(a[i],1,top);
        s[st]=i;
        if (st>top) top=st;
    }
    printf("%d",top-2);
}
int main()
{
    readfile();
    solve();
}