#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int a[maxn];
int ma11[4*maxn];
int ma21[4*maxn];
int ma12[4*maxn];
int ma22[4*maxn];
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        int val=a[tl];
        ma12[node]=val;
        ma21[node]=(-val);
        ma11[node]=0;
        ma22[node]=0;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    ma11[node]=max(ma11[2*node+1]+ma11[2*node+2],ma12[2*node+1]+ma21[2*node+2]);
    ma21[node]=max(ma21[2*node+1]+ma11[2*node+2],ma22[2*node+1]+ma21[2*node+2]);
    ma22[node]=max(ma21[2*node+1]+ma12[2*node+2],ma22[2*node+1]+ma22[2*node+2]);
    ma12[node]=max(ma11[2*node+1]+ma12[2*node+2],ma12[2*node+1]+ma22[2*node+2]);
    return;
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        ma12[node]=val;
        ma21[node]=(-val);
        ma11[node]=0;
        ma22[node]=0;
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    ma11[node]=max(ma11[2*node+1]+ma11[2*node+2],ma12[2*node+1]+ma21[2*node+2]);
    ma21[node]=max(ma21[2*node+1]+ma11[2*node+2],ma22[2*node+1]+ma21[2*node+2]);
    ma22[node]=max(ma21[2*node+1]+ma12[2*node+2],ma22[2*node+1]+ma22[2*node+2]);
    ma12[node]=max(ma11[2*node+1]+ma12[2*node+2],ma12[2*node+1]+ma22[2*node+2]);
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;++i) cin>>a[i];
        build(0,0,n);
        cout<<max(ma11[0],ma12[0])<<'\n';
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            to(0,0,n,l,a[r]);to(0,0,n,r,a[l]);
            swap(a[l],a[r]);
            cout<<max(ma11[0],ma12[0])<<'\n';
        }
    }
    return 0;
}