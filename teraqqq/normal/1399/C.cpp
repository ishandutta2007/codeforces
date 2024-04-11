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
    int n, s= 0; cin >> n;
    vi gist(3*n+228), g2(n+1);
    for(int i = 0; i < n; ++i) { int x; cin >> x; g2[x]++; }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j)
            gist[i+j] += min(g2[i], g2[j]);
        gist[2*i] += g2[i] / 2;
    }

    for(int i = 0; i <= 3*n; ++i)
        if(gist[i] > gist[s]) s = i;
    cout << gist[s] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}