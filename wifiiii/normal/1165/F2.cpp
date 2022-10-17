#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

struct node
{
    int d,t;
}a[200005];
bool cmp(node a,node b)
{
    return a.d<b.d;
}
int k[200005],kx[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int tot = 0;
    rep(i,n) cin>>k[i],tot+=k[i];
    rep(i,m) cin>>a[i].d>>a[i].t;
    sort(a+1,a+1+m,cmp);
    int lo = tot, hi = 2*tot;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        memcpy(kx, k, sizeof(int)*(n+1));
        int cnt = 0, mn = mid;
        for(int i=m;i>=1;--i)
        {
            if(a[i].d>mid) continue;
            mn = min(mn, a[i].d);
            while(kx[a[i].t]&&mn) kx[a[i].t]--,mn--,cnt++;
        }
        if(cnt>=2*tot-mid) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
}