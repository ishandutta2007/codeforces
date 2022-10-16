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
    int n, k1, k2; cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;
    int t1 = n - k1, t2 = n - k2;
    cout << (abs(k1-k2)/2+min(k1,k2) >= w && abs(t1-t2)/2+min(t1,t2) >= b ? "YES" :"NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}