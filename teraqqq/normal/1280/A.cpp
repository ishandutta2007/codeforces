#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define rsz resize

using namespace std;
using ll = long long;
using ld = double;
using vi = vector<int>;
using pi = pair<int, int>;

mt19937 rng;

const ll MOD = 1e9+7;

void solve() {
    int x; string s; cin >> x >> s;
    ll sz = s.size();
    for(int i = 1; i <= x; ++i) {
        if(s.size() < x) {
            string c = string(s.begin()+i, s.end());
            for(int k = s[i-1]-'1'; k--;) s += c;
        }
        sz += ((ll)sz-i)*((ll)s[i-1]-'1'); sz %=(ll) MOD;
    }
    cout << (sz+MOD)%MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t; while(t--) solve();
}