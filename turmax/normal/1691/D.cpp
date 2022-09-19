#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int sz;int pr[maxn];int t[4*maxn];
void build(int node,int tl,int tr)
{
    if((tr-tl)==1) {t[node]=pr[tl];return;}
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    t[node]=max(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t[node];
    if(tl>=r || tr<=l) return (-1e18);
    int tm=(tl+tr)/2;
    return max(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int getma(int l,int r)
{
    return get(0,0,sz,l,r);
}
bool check(vector<int> a,int n)
{
    pr[0]=0;for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
    sz=n+1;build(0,0,sz);
        stack <pair<int,int> > u;int nxt[n];
        for(int i=n-1;i>=0;--i)
        {
            if(a[i]<=0) continue;
            if(u.empty()) {nxt[i]=n;u.push({a[i],i});continue;}
            while(!u.empty())
            {
                pair<int,int> o=u.top();
                if(o.first>a[i]) {nxt[i]=o.second;break;}
                u.pop();
            }
            if(u.empty()) {nxt[i]=n;}
            u.push({a[i],i});
        }
        for(int i=0;i<n;++i) {if(a[i]>0) {int o=nxt[i];if(getma(i+1,o+1)>pr[i+1]) return false;}}
        return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;vector<int> a(n);for(int i=0;i<n;++i) cin>>a[i];
        bool ok=false;for(int i=0;i<n-1;++i) {if(a[i]>0 && a[i+1]>0) {puts("NO");ok=true;break;}} if(ok) continue;
        ok=check(a,n);reverse(a.begin(),a.end());ok=(ok && check(a,n));
        puts(ok ? "YES" : "NO");
    }
    return 0;
}