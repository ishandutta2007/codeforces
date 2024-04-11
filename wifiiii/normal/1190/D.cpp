#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

struct node
{
    int x,y;
    bool operator <(const node &n) const
    {
        return y>n.y || (y==n.y && x<n.x);
    }
}a[200005];
int xx[200005],yy[200005];
int bit[200005],n;
int sum(int x) {int ret=0;for(;x;x-=x&-x) ret+=bit[x];return ret;}
void add(int x) {for(;x<=n;x+=x&-x) bit[x]++;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    forii cin>>a[i].x>>a[i].y,xx[i]=a[i].x;
    sort(xx+1,xx+1+n);
    int l1=unique(xx+1,xx+1+n)-xx-1;
    forii a[i].x=lower_bound(xx+1,xx+1+l1,a[i].x)-xx;
    sort(a+1,a+1+n);
    ll ans=0;
    vector<ll> v;
    v.push_back(a[1].x);
    for(ll i=2;i<=n+1;++i)
    {
        if(a[i].y==a[i-1].y) v.push_back(a[i].x);
        else
        {
            ll l=0;
            for(ll j=0;j<v.size();++j)
            {
                ll tmp = sum(v[j]-1) - sum(l);
                ans -= tmp*(tmp+1)/2;
                l=v[j];
            }
            ll tmp2=sum(n)-sum(v[v.size()-1]);
            ans -= tmp2*(tmp2+1)/2;
            for(ll i:v) if(sum(i)==sum(i-1)) add(i);
            ll tmp=sum(n);
            ans += tmp*(tmp+1)/2;
            v.clear();
            v.push_back(a[i].x);
        }
    }
    cout<<ans<<endl;
}