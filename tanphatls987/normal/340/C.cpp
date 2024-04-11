#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

const int maxd=100000;
long long n,a[maxd];
int readfile()
{
    cin>>n;
    FOR(i,n) cin>>a[i];
    sort(a,a+n);
}
long long gcd(long long x,long long y)
{
    while (y)
    {
        long long tmp=y;
        y=x%y;
        x=tmp;
    }
    return x;
}
int solve()
{
    long long sum=0;
    FOR(i,n) sum+=a[i];
    long long ans=sum;
    sum-=n*a[0];
    for(int i=1;i<n;i++)
    {
        ans+=2*sum;
        sum-=(n-i)*(a[i]-a[i-1]);
        //cout<<ans<<'\n';
    }
    long long m=n;
    n/=gcd(ans,n);ans/=gcd(ans,m);
    cout<<ans<<" "<<n;
}
int main()
{
    readfile();
    solve();
}