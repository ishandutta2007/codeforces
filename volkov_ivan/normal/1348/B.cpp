#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set <int> have;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        have.insert(x);
    }
    if ((int) have.size() > k) {
        cout << -1 << endl;
        return;
    }
    vector <int> ans;
    for (int elem : have) ans.push_back(elem);
    while (ans.size() < k) ans.push_back(ans[0]);
    cout << n * ans.size() << endl;
    for (int i = 0; i < n; i++) {
        for (int elem : ans) cout << elem << ' ';
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}