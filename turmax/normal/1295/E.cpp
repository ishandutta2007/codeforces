#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200005;
int t[4*maxn];
int z[4*maxn];
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tl>=l && tr<=r)
    {
        t[node]+=val;
        z[node]+=val;
        return;
    }
    to(2*node+1,tl,(tl+tr)/2,l,r,val);
    to(2*node+2,(tl+tr)/2,tr,l,r,val);
    z[node]=min(z[2*node+1]+t[node],z[2*node+2]+t[node]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        to(0,0,maxn,a[i],n+1,b[i]);
    }
    to(0,0,maxn,n+1,maxn,1e18);
    int c=1e18;
    for(int i=0;i<(n-1);++i)
    {
        to(0,0,maxn,a[i],n+1,-b[i]);
        to(0,0,maxn,0,a[i],b[i]);
        //cout<<z[0]<<endl;
        c=min(c,z[0]);
    }
    cout<<c;
    return 0;
}