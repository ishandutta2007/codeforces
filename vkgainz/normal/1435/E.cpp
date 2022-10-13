#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
ll a,b,c,d;
ll get(ll k) {
    ll ans = -a*(k+1);
    ans+=d*k*(k+1)/2*b;
    return ans;
}
void solve() {
    cin >> a >> b >> c >> d;
    if(b*c<a) cout << -1 << endl;
    else {
        ll ans = a;
        ll l = c/d;
        ll over = get(l);
        ans = max(-over,ans);
        ll left = min(max(a/(b*d)-3,0LL),l);
        ll right = min(a/(b*d)+3,l);
        for(ll i=left;i<=right;i++)  {
            ans = max(-get(i),ans);
        }
        cout << ans << endl;
    }
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}