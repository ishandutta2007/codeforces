#include <bits/stdc++.h>
using namespace std;
long long v[500005],st[500005],dr[500005],nxt[500005],lst[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        v[i]=c-'0';
    }
    long long sc=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]==0)
            st[i]=0;
        else
            st[i]=1+st[i-1];
        mx=max(mx,st[i]);
        sc+=mx;
    }
    for(i=n;i>=1;--i)
    {
        if(v[i]==0)
            dr[i]=0;
        else
            dr[i]=1+dr[i+1];
        lst[i]=n+1;
    }
    for(i=n;i>=1;--i)
    {
        if(st[i])
        {
            for(j=i;j>i-st[i];--j)
                nxt[j]=lst[dr[j]];
            for(j=i;j>i-st[i];--j)
                lst[st[j]]=j;
            i-=st[i];
            ++i;
        }
    }
    s+=sc;
    for(i=1;i<n;++i)
    {
        if(v[i])
            sc-=nxt[i]-i;
        s+=sc;
    }
    cout<<s;
    return 0;
}