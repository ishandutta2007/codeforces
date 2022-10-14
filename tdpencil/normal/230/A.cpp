#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll s, n;
    cin >> s >> n;
    vector<pair<ll, ll>> A;
    while(n--) {
        ll x, y;
        cin >> x >> y;
        A.push_back({x, y});
    }
    sort(A.begin(), A.end());
    bool cd=true;
    for(auto &num: A) {
        if(num.first < s) {
            s += num.second;
        } else {
            cd = false;
            break;
        }
    }
    cout << (cd ? "YES\n":"NO\n"); 
}