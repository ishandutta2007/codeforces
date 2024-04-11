#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
const ll INF = 0x1fffffffffffffff;
bool chmin(ll& a, ll b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(ll& a, ll b){ if(a < b){ a = b; return 1; } return 0; }


void solve(){
    vector<ll> a(4);
    for(ll& i : a) cin >> i;
    sort(a.begin(), a.end());
    ll ans = 0;
    do{
        chmax(ans, min(a[0], a[1]) * min(a[2], a[3]));
    }while(next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
}
int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}