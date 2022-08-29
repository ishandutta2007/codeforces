#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
const ll INF = 0x1fffffffffffffff;
bool chmin(ll& a, ll b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(ll& a, ll b){ if(a < b){ a = b; return 1; } return 0; }


ll ceil(ll p, ll q){
    if(p >= 0) return (p + q - 1) / q;
    else return p / q;
}
ll floor(ll p, ll q){
    if(p >= 0) return p / q;
    else return (p - q + 1) / q;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(n != abs(x1 * y2 - y1 * x2)){
        cout << "No" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(x1 < 0 || x1 == 0 && y1 < 0){
        x1 = -x1;
        y1 = -y1;
    }
    if(x2 < 0 || x2 == 0 && y2 < 0){
        x2 = -x2;
        y2 = -y2;
    }
    vector<pll> a(2000001, {INF, -INF});
    auto update = [&](ll x, ll y_p, ll y_q = 1){
        chmin(a[x].first, ceil(y_p, y_q));
        chmax(a[x].second, floor(y_p, y_q));
    };
    if(x1) for(ll x = 0; x <= x1; x++){
        update(x, y1 * x, x1);
        update(x + x2, y1 * x + y2 * x1, x1);
    }
    if(x2) for(ll x = 0; x <= x2; x++){
        update(x, y2 * x, x2);
        update(x + x1, y2 * x + y1 * x2, x2);
    }
    unordered_set ans(initializer_list<pair<int, int>>{}, 400000, [](pair<int, int> x){ return (ll)x.first << 32 ^ x.second; });
    for(ll x = 0; x < a.size(); x++) for(ll y = a[x].first; y <= a[x].second; y++) if(ans.emplace(x, y).second){
        cout << x << ' ' << y << '\n';
        ans.emplace(x + x1, y + y1);
        ans.emplace(x + x2, y + y2);
        ans.emplace(x + x1 + x2, y + y1 + y2);
    }
}