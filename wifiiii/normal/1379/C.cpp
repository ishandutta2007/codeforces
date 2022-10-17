
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
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
#define pb push_back

const int maxn = 200005;
int a[maxn], b[maxn];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ij cin>>a[i]>>b[i];
        vl v;
        ij v.pb(a[i]);
        sort(all(v));
        reverse(all(v));
        vl s=v;
        for(int i=1;i<s.size();++i)s[i]+=s[i-1];
        ll ans = s[min((int)s.size()-1,n-1)];
        for(int i=1;i<=m;++i) {
            int cur=b[i];
            int pos=upper_bound(all(v),cur,[&](ll i,ll j){return i>j;})-v.begin();
            if(pos < n) {
                if(pos == 0) ans = max(ans, 1ll * (n-1) * b[i] + a[i]);
                else {
                    if(a[i] >= b[i]) ans = max(ans, 1ll * (n-pos) * b[i] + s[pos-1]);
                    else ans = max(ans, 1ll * (n-pos-1) * b[i] + s[pos-1] + a[i]);
                }
            }
        }
        cout << ans << endl;
    }
}