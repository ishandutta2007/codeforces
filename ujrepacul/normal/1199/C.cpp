#include <bits/stdc++.h>

using namespace std;
int v[400005],lg[400005];
int vn[400005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr,mx=0;
    cin>>n>>m;
    int ni=n;
    m*=8;
    for(i=2;i<=n;++i)
        lg[i]=1+lg[i/2];
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        int lgc=lg[i];
        if(lg[i]==lg[i-1] && i!=1)
            ++lgc;
        if(lgc*n<=m)
            k=i;
    }
    sort(v+1,v+n+1);
    cnt=0;
    j=-1;
    v[0]=-1;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=v[i-1])
        {
            vn[++j]=cnt;
            cnt=1;
        }
        else
            ++cnt;
    }
    vn[++j]=cnt;
    n=j;
    for(i=1;i<=n;++i)
        v[i]=vn[i]+v[i-1];
    for(i=min(n,k);i<=n;++i)
    {
        mx=max(mx,v[i]-v[max(0,i-k)]);
    }
    cout<<ni-mx;
    return 0;
}