#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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

ll h[100005],s[100005];
int n;ll a,r,m;
ll calc(ll k) {
    int idx=lower_bound(h+1,h+1+n,k)-h;
    ll L=(idx-1)*k-s[idx-1],R=s[n]-s[idx-1]-k*(n-idx+1);
    ll p=min(L,R);
    ll tmp=p*m;
    L-=p,R-=p;
    tmp+=L*a+R*r;
    return tmp;
}
int main() {
    cin>>n>>a>>r>>m;
    m=min(m,a+r);
    ii cin>>h[i];
    sort(h+1,h+1+n);
    ii s[i]=s[i-1]+h[i];
    ll lo=0,hi=1e9;
    ll ans=2e18;
    while(hi - lo > 3) {
        ll k1=lo+(hi-lo)/3,k2=hi-(hi-lo)/3;
        assert(k1 <= k2);
        ll tmp1=calc(k1),tmp2=calc(k2);
        ans = min(ans, tmp1), ans = min(ans, tmp2);
//        cout << k1 << "->" << tmp1 << ", " << k2 << "->" << tmp2 << endl;
        if(tmp1 < tmp2) {
            hi = k2;
        } else {
            lo = k1;
        }
    }
    for(int i=lo;i<=hi;++i) ans=min(ans,calc(i));
    cout << ans << endl;
}