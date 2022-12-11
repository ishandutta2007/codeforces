#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    long n,t,c,i,a[200000],sum,ans,j;
    cin>>n>>t>>c;
    for(i=0;i<n;i++) cin>>a[i];
    sum=0;ans=0;
    j=0;i=0;
    while (i<n)
    {
        if (a[j]<=t) {}else i=j+1;
        if (j-i+1>=c) ans++;
        j++;
        if (j==n) break;

    }
    cout<<ans;
}