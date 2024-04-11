#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxt=2e6+5;
const int maxn=2e6+5;
int nxt[maxn];int a[maxn];
int t;
int f(int x1,int x,int cur)
{
    int y=(x1-x+cur*cur);
    int o=sqrt((int) y);
    if(o*o+o<y)
    {
        return (o+1);
    }
    else
    {
        return o;
    }
}
int l,r;
void f2(int pos,int val)
{
    l=max(l,val*val-a[pos]);
    r=min(r,val*val+val-a[pos]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;for(int i=0;i<n;++i) cin>>a[i]; sort(a,a+n);
    nxt[maxn-1]=(-1);int cur1=(n-1);
    for(int i=maxn-2;i>=0;--i)
    {
        if(cur1>=0 && a[cur1]==i)
        {
            while(cur1>=0 && a[cur1]==i) --cur1;
            nxt[i]=cur1+1;
        }
        else
        {
            nxt[i]=nxt[i+1];
        }
    }
    for(t=1;t<=maxt;++t)
    {
        l=0,r=1e18;
        int cur=a[0];int curt=t;
        f2(0,curt);
        while(true)
        {
            int val1=cur+curt+1;int pos;
            if(val1>a[n-1]) {f2(n-1,curt);break;}
            else {pos=nxt[val1];}
            int curt1=curt;curt=f(a[pos],cur,curt1);cur=a[pos];f2(pos-1,curt1);if(r<l) break; f2(pos,curt);if(r<l) break;
        }
        if(r>=l)
        {
            cout<<l;return 0;
        }
    }
    return 0;
}