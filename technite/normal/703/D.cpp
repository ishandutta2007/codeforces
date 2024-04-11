#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
const int sz=1e7+1;
struct node{
ll s;
}st[sz];
int n;  
void upd(int l1,int x, int i=1,int l2=0,int r2=n-1)
{
    if(l2==r2)
    {
        //st[i].mx=x;
        st[i].s=x;
        //st[i].mxl=x;
        //st[i].mxr=x;
        return;
    }
    int m2=(l2+r2)/2;
    if(l1<=m2)
        upd(l1,x,2*i,l2,m2);
    else
    upd(l1,x,2*i+1,m2+1,r2);
    //st[i].mx=max({st[2*i].mx,st[2*i+1].mx,st[2*i].mxr+st[2*i+1].mxl});
    //st[i].mxl=max(st[2*i].mxl,st[2*i+1].mxl+st[2*i].s);
    //st[i].mxr=max(st[2*i+1].mxr,st[2*i+1].s+st[2*i].mxr);
    st[i].s=st[2*i].s^st[2*i+1].s;
}
ll qry(int l1,int r1,int i=1,int l2=0,int r2=n-1)
{
    if(l1<=l2&&r2<=r1)
    /*for min*///return st[i].mx;
    /*for sum*/return st[i].s;
    int m2=(l2+r2)/2;
    /*for min*///return max(l1<=m2?qry(l1,r1,2*i,l2,m2):0,m2<r1?qry(l1,r1,2*i+1,m2+1,r2):(int)0);
    /*for sum*/return (l1<=m2?qry(l1,r1,2*i,l2,m2):0)^(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):0);
}
 
int main()
{
    fast;
    int q;
    cin>>n;
    vector<int> v(n);
    vi pref(n+1,0);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        pref[i+1]=pref[i]^v[i];
    }
    vector<pair<int,pair<int,int>>> x;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        x.push_back({b,{a,i}});
    }
    sort(x.begin(),x.end());
    int idx=0;
    map<int,int> m;
    vector<int> ans(q);
    for(int i=0;i<n;i++)
    {
        if(m.find(v[i])!=m.end())
        {
            upd(m[v[i]],0);
        }
        m[v[i]]=i;
        upd(m[v[i]],v[i]);
        while(i==x[idx].first)
        {
            int aaa=qry(x[idx].S.F,x[idx].F);
            aaa^=pref[x[idx].F+1]^pref[x[idx].S.F];
            ans[x[idx].S.S]=aaa;
            idx++;
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<'\n';
    }
}