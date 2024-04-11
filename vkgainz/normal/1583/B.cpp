#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    set<int> in;
    for (int i = 0; i < n; i++) {
        in.insert(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i], --c[i];
        in.erase(b[i]);
    }
    if (!in.empty()) {
        for (int i = 0; i < n; i++) {
            if (i != *in.begin()) {
                cout << *in.begin() + 1 << " " << i + 1 << "\n";
            }
        }
    } else {
        cout << "bayus" << "\n";
    }
}
int main() {
    int t; cin >> t;
    while (t--) { solve(); }
}