#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> par(n);
    for(int i = 0; i < n; ++i) par[i] = i;
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    };
    int ans = 0;
    for(int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int x = find(u), y = find(v);
        if(x == y) ++ans;
        par[x] = y;
    }
    cout << ans << '\n';
}