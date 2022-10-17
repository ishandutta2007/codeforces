#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

unordered_map<int,ll> mp;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll cnt = 0, sum = 0;
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        cnt += x / 2;
        sum += x & 1;
        if(cnt >= sum) {
            ll lo = 0, hi = cnt;
            while(lo < hi) {
                ll mid = (lo + hi) / 2;
                if(sum+2*mid > cnt-mid) hi = mid;
                else lo = mid + 1;
            }
            ll mx = 0, mi = -1;
            for(ll i = max(lo-3,0ll); i <= min(hi+3, cnt); ++i) {
                if(min(sum+2*i, cnt-i) >= mx) {
                    mx = min(sum+2*i, cnt-i);
                    mi = i;
                }
            }
            ll p = min(sum+2*mi, cnt-mi);
            ans += p;
            cnt = cnt - mi - p;
            sum = sum + 2 * mi - p;
            sum += 2 * cnt;
            cnt = 0;
        } else {
            sum -= cnt;
            ans += cnt;
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
    if(cnt <= sum) cout << cnt << endl;
    else {
        ll ans = 0;
        ll lo = 0, hi = cnt;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            if(sum+2*mid > cnt-mid) hi = mid;
            else lo = mid + 1;
        }
        for(ll i = max(lo-3,0ll); i <= min(hi+3, cnt); ++i) {
            ans = max(ans, min(sum+2*i, cnt-i));
        }
        cout << ans << endl;
    }
}