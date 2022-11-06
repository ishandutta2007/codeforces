#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, int> m;
    int cnt = 0;
    while (n--) {
        int a; cin >> a;
        ++m[a];
    }
    if (m.size() == 2) {
        auto it = m.begin();
        auto itt = it; ++itt;
        if (it->second == itt->second) {
            cout << "YES" << endl;
            cout << it->first << ' ' << itt->first << endl;
        }
        else cout << "NO" << endl;
        return 0;
    }
    cout << "NO" << endl;
}