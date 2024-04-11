#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int pr[maxn];
int a1[maxn];int a2[maxn];
int t1[4*maxn];int t2[4*maxn];
void build1(int node,int tl,int tr)
{
    if((tr-tl)==1) {t1[node]=a1[tl];return;}
    int tm=(tl+tr)/2;
    build1(2*node+1,tl,tm);build1(2*node+2,tm,tr);
    t1[node]=min(t1[2*node+1],t1[2*node+2]);
}
void build2(int node,int tl,int tr)
{
    if((tr-tl)==1) {t2[node]=a2[tl];return;}
    int tm=(tl+tr)/2;
    build2(2*node+1,tl,tm);build2(2*node+2,tm,tr);
    t2[node]=max(t2[2*node+1],t2[2*node+2]);
}
int get1(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t1[node];
    }
    if(tl>=r || tr<=l) return 1e18;
    int tm=(tl+tr)/2;
    return min(get1(2*node+1,tl,tm,l,r),get1(2*node+2,tm,tr,l,r));
}
int get2(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t2[node];
    }
    if(tl>=r || tr<=l) return (-1e18);
    int tm=(tl+tr)/2;
    return max(get2(2*node+1,tl,tm,l,r),get2(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int pr[n+1];pr[0]=0;
        map <int,vector <int> > d;
        for(int i=0;i<n;++i)
        {
            if(i%2==0) pr[i+1]=pr[i]+a[i];
            else pr[i+1]=pr[i]-a[i];
        }
        for(int i=0;i<=n;++i)
        {
            if(i%2==0) {a1[i]=1e18;a2[i]=pr[i];}
            else {a1[i]=pr[i];a2[i]=(-1e18);}
        }
        for(int i=0;i<=n;++i) {if(!d.count(pr[i])) d[pr[i]]={i}; else d[pr[i]].push_back(i);}
        build1(0,0,n+1);build2(0,0,n+1);
        int res=0;
        for(int l=0;l<n;++l)
        {
            int low=l;
            int up=(n+1);
            if(l%2==0)
            {
                while((up-low)>1)
                {
                    int mid=(low+up)/2;
                    if(get1(0,0,n+1,l,mid)>=pr[l] && get2(0,0,n+1,l,mid)<=pr[l])
                    {
                        low=mid;
                    }
                    else
                    {
                        up=mid;
                    }
                }
            }
            else
            {
                while((up-low)>1)
                {
                    int mid=(low+up)/2;
                    if(get1(0,0,n+1,l,mid)>=pr[l] && get2(0,0,n+1,l,mid)<=pr[l])
                    {
                        low=mid;
                    }
                    else
                    {
                        up=mid;
                    }
                }
            }
            int val=pr[l];
            int ans=upper_bound(d[val].begin(),d[val].end(),low)-upper_bound(d[val].begin(),d[val].end(),l);
            res+=ans;
        }
        cout<<res<<endl;
    }
    return 0;
}