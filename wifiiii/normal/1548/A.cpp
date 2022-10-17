#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> bigger(n);
    int ans = n;
    auto add = [&](int u, int v) {
        if(u > v) swap(u, v);
        if(!bigger[u]) --ans;
        bigger[u]++;
    };
    auto del = [&](int u, int v) {
        if(u > v) swap(u, v);
        bigger[u]--;
        if(!bigger[u]) ++ans;
    };
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        add(u, v);
    }
    int q;
    cin >> q;
    while(q--) {
        int op;
        cin >> op;
        if(op == 3) {
            cout << ans << '\n';
        } else {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if(op == 1) add(u, v);
            else del(u, v);
        }
    }
}