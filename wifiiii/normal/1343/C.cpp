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
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll neg = 0, pos = 0, last = 0;
        ll ans = -1e18;
        for(int i=1;i<=n;++i) {
            ll x;
            cin >> x;
            if(x * last > 0) {
                if(x > 0) pos = max(pos, neg + x), ans = max(ans, pos);
                else neg = max(neg, pos + x), ans = max(ans, neg);
            } else {
                if(x > 0) pos = neg + x, ans = pos;
                else neg = pos + x, ans = neg;
            }
            last = x;
        }
        cout << ans << endl;
    }
}