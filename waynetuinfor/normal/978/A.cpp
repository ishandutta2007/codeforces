#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<int> s;
    vector<int> r;
    for (int i = n - 1; i >= 0; --i) {
        if (s.count(a[i])) continue;
        s.insert(a[i]);
        r.push_back(a[i]);
    }
    cout << r.size() << endl;
    for (int i = r.size() - 1; i >= 0; --i) cout << r[i] << ' '; cout << endl;
}