#include <bits/stdc++.h>
using namespace std;
int fv[25];
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        for(j=0;j<=21;++j)
        {
            fv[j]+=(a&1);
            a>>=1;
        }
    }
    for(j=0;j<=21;++j)
    {
        for(i=1;i<=fv[j];++i)
        {
            v[i]+=(1LL<<j);
        }
    }
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        rz+=v[i]*1LL*v[i];
    }
    cout<<rz;
    return 0;
}