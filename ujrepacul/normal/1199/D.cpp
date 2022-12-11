#include <bits/stdc++.h>

using namespace std;
int v[200005],rz[200005];
struct ura
{
    int fel,a,b;
}q[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr,mx=0,cur=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        rz[i]=-1;
    }
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>q[i].fel;
        if(q[i].fel==1)
            cin>>q[i].a>>q[i].b;
        else
            cin>>q[i].a;
    }
    for(i=m;i>=1;--i)
    {
        if(q[i].fel==2)
            cur=max(cur,q[i].a);
        else
        {
            if(rz[q[i].a]==-1)
                rz[q[i].a]=max(q[i].b,cur);
        }
    }
    for(i=1;i<=n;++i)
        if(rz[i]==-1)
            rz[i]=max(v[i],cur);
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}