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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vi> x(2); vi res(n);
    int k = 0;
    for(int i = 0; i < n; ++i) {
        int y = s[i] - '0';
        if(x[1-y].empty()) x[1-y].push_back(++k);

        res[i] = x[1-y].back();
        x[y].push_back(x[1-y].back());
        x[1-y].pop_back();
    }

    cout << k << '\n';
    for(int i : res) cout << i << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}