#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int mx = 1, mn = n;
    vector<ar<int, 2>> g(m);

    for(int i = 0; i < m; i++) {
        cin >> g[i][0] >> g[i][1];
        if(g[i][0] > g[i][1])
            swap(g[i][0], g[i][1]);
    }

    for(int i = 0; i < m; i++) {
        mx = max(mx, g[i][0]);
        mn = min(mn, g[i][1]);
    }

    cout << max(0, mn - mx) << "\n";
}