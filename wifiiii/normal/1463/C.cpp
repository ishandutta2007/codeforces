#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

#define int ll
ll a[100005],b[100005];
int32_t main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin >> n;
        int cur = 0, l = 0, r = 0, v = 1, ans = 0;
        for(int i=1;i<=n;++i) cin>>a[i]>>b[i];a[n+1]=1e12;
        for(int i=1;i<=n;++i) {
            int t = a[i], x = b[i];
            if(t < r) {
                int tmp = cur + (t - l) * v;
                if(a[i+1] - a[i] <= r - t) {
                    int nxt = cur + (a[i+1] - l) * v;
                    int mn = min(tmp, nxt), mx = max(tmp, nxt);
                    if(mn <= x && x <= mx) ++ans;
                } else {
                    int nxt = cur + (r - l) * v;
                    int mn = min(tmp, nxt), mx = max(tmp, nxt);
                    if(mn <= x && x <= mx) ++ans;
                }
            } else {
                cur = cur + (r - l) * v;
                l = r = t; v = 0;
                if(x > cur) {
                    l = t, r = t + x - cur, v = 1;
                } else if(x < cur) {
                    l = t, r = t + cur - x, v = -1;
                }
                if(abs(l - r) <= abs(a[i+1] - a[i])) ++ans;
            }
        }
        cout << ans << endl;
    }
}