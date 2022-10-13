#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

void rev(vector<int> &v, int p) {
    ans.push_back(p + 1);
    vector<int> a(p + 1);
    for (int i = 0; i <= p; i++)
        a[i] = v[i];
    reverse(a.begin(), a.end());
    for (int i = 0; i <= p; i++)
        v[i] = a[i];
}

int pos(vector<int> &v, int x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x)
            return i;
    }
    return -1;
}

void solve() {
    int n; cin >> n;
    ans.clear();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != ((i + 1) % 2)) {
            cout << -1 << "\n";
            return;
        }
    }
    for (int i = n / 2; i >= 1; i--) {
        int x = pos(a, 2 * i + 1), y = pos(a, 2 * i);
        rev(a, x);
        x = pos(a, 2 * i + 1), y = pos(a, 2 * i);
        rev(a, y - 1);
        x = pos(a, 2 * i + 1), y = pos(a, 2 * i);
        rev(a, y + 1);
        x = pos(a, 2 * i + 1), y = pos(a, 2 * i);
        rev(a, x);
        rev(a, 2 * i);
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}