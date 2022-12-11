#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr;
    cin>>n>>st>>dr;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        int ok=1;
        for(j=i-1;j>=max(1LL,i-st);--j)
            if(v[j]<=v[i])
                ok=0;
        for(j=i+1;j<=min(n,i+dr);++j)
            if(v[j]<=v[i])
                ok=0;
        if(ok==1)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}