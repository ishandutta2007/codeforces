#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

ll powi(ll x, ll y){
    ll ans = 1;
    while(y--){
        ans *= x;
    }
    return ans;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    ll k = powi(2, m)-n;
    ll median = (k-1)/2;
    vector<ll> removed(n, 0);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        removed[i] = stoll(s, 0, 2);
    }
    sort(removed.begin(), removed.end());
    for(ll i : removed){
        if(i <= median){
            median++;
        }
    }
    string out = bitset<60>(median).to_string();
    out = out.substr(out.size()-m, m);
    cout << out << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}