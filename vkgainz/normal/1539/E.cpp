#include <bits/stdc++.h>
using namespace std;

void merge(array<int, 2> &x, array<int, 2> y) {
    x[0] = max(x[0], y[0]), x[1] = min(x[1], y[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> k(n + 1);
    vector<int> al(n + 1), bl(n + 1);
    vector<int> ar(n + 1), br(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        cin >> al[i] >> bl[i];
        cin >> ar[i] >> br[i];
    }
    vector<array<bool, 2>> dp(n + 2);
    dp[n + 1] = {1, 1};
    array<int, 2> lst = {n + 1, n + 1};
    array<int, 2> l, r;
    array<int, 2> bad = {n + 2, n + 2};
    l = {0, m}, r = {0, m};

    vector<array<int, 2>> nxt(n + 1);
    for(int i = 0; i <= n; i++) {
        nxt[i] = {-1, -1};
    }
    for(int i = n; i >= 0; i--) {
        int j = lst[1];
        if(l[0] <= k[i] && k[i] <= l[1] && al[i] <= k[i] && k[i] <= bl[i]) {
            if(bad[1] > j) {
                dp[i][0] = 1;
                nxt[i][0] = j;
            }
        }
        j = lst[0];
        if(r[0] <= k[i] && k[i] <= r[1] && ar[i] <= k[i] && k[i] <= br[i]) {
            if(bad[0] > j) {
                dp[i][1] = 1;
                nxt[i][1] = j;
            }
        }
        
        if(dp[i][0] == 1)
            r = {ar[i], br[i]}, lst[0] = i;
        else
            merge(r, {ar[i], br[i]});
        if(dp[i][1] == 1)
            l = {al[i], bl[i]}, lst[1] = i;
        else
            merge(l, {al[i], bl[i]});
        if(k[i] < al[i] || k[i] > bl[i])
            bad[0] = i;
        if(k[i] < ar[i] || k[i] > br[i])
            bad[1] = i;
    }
    if(!dp[0][0] && !dp[0][1]) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << "\n";
    int curr = 1 - dp[0][0];
    for(int i = 0; i <= n; i++) {
        if(i > 0)
            cout << curr << " ";
        if(dp[i][curr] == 1) {
            curr = 1 - curr;
        }
    }
}