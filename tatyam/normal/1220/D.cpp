#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(60);
    for(ll& i : a){
        cin >> i;
        cnt[__builtin_ctzll(i)]++;
    }
    ll mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    a.erase(remove_if(a.begin(), a.end(), [&](ll x){ return __builtin_ctzll(x) == mx; }), a.end());
    cout << a.size() << endl;
    for(ll i : a) cout << i << ' ';
}