#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int t[4*maxn];
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        t[node]=max(t[node],val);
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=max(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    if(tl>=r || tr<=l)
    {
        return (-1);
    }
    int tm=(tl+tr)/2;
    return max(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<(4*maxn);++i) t[i]=(-1);
    int n;
    cin>>n;
    vector <int> v[n+1];
    int a[n];
    for(int i=0;i<=n;++i)
    {
        v[i].push_back(-1);
    }
    bool o=false;
    for(int i=0;i<n;++i) {cin>>a[i];if(a[i]!=1) o=true;a[i]--;v[a[i]].push_back(i);}
    if(!o)
    {
        cout<<1;
        return 0;
    }
    for(int i=0;i<=n;++i)
    {
        v[i].push_back(n);
    }
    for(int i=0;i<=n;++i)
    {
        bool h=false;
        //cout<<i<<" i "<<endl;
        for(int j=0;j<v[i].size()-1;++j)
        {
            int l=v[i][j];
            int r=v[i][j+1];
            //cout<<l<<" l "<<r<<" r "<<endl;
            //cout<<get(0,0,maxn,0,l+2)<<" get "<<endl;
            if(get(0,0,maxn,0,l+2)<r+1)
            {
                 h=true;
            }
            to(0,0,maxn,l+1,r+1);
        }
        if(!h)
        {
            cout<<(i+1);
            return 0;
        }
    }
    cout<<(n+2);
    return 0;
}