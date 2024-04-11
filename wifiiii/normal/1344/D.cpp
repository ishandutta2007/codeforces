#include<bits/stdc++.h>
 
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'
#define int ll
int ans[100005];
struct node {
    int v,id;
    bool operator < (const node & n) const {
        return v < n.v;
    }
}a[100005],b[100005];
int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    ii cin >> a[i].v, a[i].id = i;
    sort(a+1,a+1+n);
    ll lo = -3e18, hi = 1e18;
    while(lo < hi) {
        ll mid = (lo + hi) >= 0 ? (lo + hi + 1) / 2 : (lo + hi) / 2;
        ll cnt = 0;
        for(int i=1;i<=n;++i) {
            if(a[i].v < mid) continue;
            ll l = 0, r = 1e9;
            while(l < r) {
                ll m = l + r + 1 >> 1;
                if(3 * m * m > a[i].v - mid) r = m - 1;
                else l = m;
            }
            l = min(l, a[i].v);
            cnt += l;
        }
        if(cnt < k) hi = mid - 1;
        else lo = mid;
    }
    for(int i=1;i<=n;++i) {
        if(a[i].v < lo) continue;
        ll xx = sqrt(1.0*(a[i].v-lo)/3);
        ll tmp = a[i].v;
        for(ll j=max(0ll,xx-5);j<=a[i].v;++j) if(3*j*j>a[i].v-lo) {tmp=j-1;break;}
        ans[a[i].id] = tmp;
        b[i].v = -3*tmp*tmp+a[i].v; b[i].id = a[i].id;
    }
    ll sum=0;
    ii sum+=ans[i];
    sort(b+1,b+1+n);
    for(int i=1;i<=sum-k;++i) ans[b[i].id]--;
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
}