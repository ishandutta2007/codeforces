#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;

const int INF = 1e9;
const ll LINF = 1e18;

bool solve() {
    int n; cin >> n;
    vi a(n); for(int& x : a) cin >> x;
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; ++i)
        if(a[i+1] - a[i] > 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) cout << (solve() ? "YES" : "NO") << '\n';
}