#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>n;
    n*=2;
    if((n*(n+1)/2)%2==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    int pz=1;
    for(i=1;i<=n;++i)
    {
        v[pz]=i;
        if(i&1)
        {
            pz+=(n/2);
            if(pz>n)
                pz-=n;
        }
        else
            pz++;
    }
    for(i=1;i<=n;++i)
        cout<<v[i]<<' ';
	return 0;
}