#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <random>

#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())
#define eb emplace_back
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int p = 1, q = 1;

    while (s[p] == '0' || s[p-1] == '0') ++p;
    reverse(all(s));
    while (s[q] == '1' || s[q-1] == '1') ++q;

    
    cout << (p + q > n ? "YES" :"NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}