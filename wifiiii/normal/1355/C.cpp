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

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0, ans2 = 0;
    for(ll k=c;k<=d;++k) {
        if(k-c+1 <= b) ans += c*(b-max(a, k-c+1)+1);
        if(k-c >= a) {
            ll an = k-min(k-c, b), a1 = k-a, len = a1-an+1;
            ans += (a1 + an) * len / 2;
        }
    }
    for(ll k=c;k<=d;++k) {
        if(b >= k-b+1) ans2 += b * (b - max(a, k-b+1) + 1);
        if(k-b >= a) {
            ll a1 = k-a+1, an = k-min(b,k-b)+1, len = a1-an+1;
            ans2 += (a1 + an) * len / 2;
        }
    }
    cout << ans - ans2 +1ll *  (b - a + 1) * (d - c + 1) << endl;
}