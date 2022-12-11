#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

typedef long long ll;

#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")

using namespace std;

const int maxd=100001;

string a;
int n,f[maxd],h[maxd]={0},p[maxd],t[maxd]={0};
int failure_func()
{
    f[0]=f[1]=0;
    t[1]=t[0]=0;
    FOR(i,2,n)
    {
        int j=f[i-1];
        while (a[j]!=a[i-1]&&j) j=f[j];
        if (a[j]==a[i-1]) f[i]=j+1;else f[i]=0;
        j=f[i];
        h[f[i]]++;
        t[i]=f[f[i]];
    }
}
int solve()
{
    failure_func();
    p[0]=n;
    int top=0;
    for(int i=n;i>0;i--) h[f[i]]+=h[i];
    while (n)
    {
        if (h[n]) p[++top]=n;
        n=f[n];
    }
    printf("%d\n",top+1);
    for(int i=top;i>=0;i--) printf("%d %d\n",p[i],h[p[i]]+1);
}
int main()
{
    cin>>a;
    n=a.length();
    solve();
}