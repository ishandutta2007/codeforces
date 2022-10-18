#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        cin >> deg[i];
    }
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (true) {
        bool ch = false;
        for (int i = 0; i < n; i++) {
            if (deg[i] == n - 1) {
                deg.erase(deg.begin() + i);
                a.erase(a.begin() + i);
                n--;
                ch = true;
                break;
            } else if (deg[i] == 0) {
                deg.erase(deg.begin() + i);
                a.erase(a.begin() + i);
                n--;
                for (int j = 0; j < n; j++) {
                    deg[j]--;
                }
                ch = true;
                break;
            }
        }
        if (!ch) {
            break;
        }
    }
    if (n <= 2) {
        cout << "! 0 0" << endl;
        return 0;
    }
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (deg[i] > deg[j]) {
                p.emplace_back(i, j);
            } else {
                p.emplace_back(j, i);
            }
        }
    }
    sort(p.begin(), p.end(), [&](auto i, auto j) {
        return deg[i.first] - deg[i.second] > deg[j.first] - deg[j.second];
    });
    for (auto [j, i] : p) {
        cout << "? " << a[j] << " " << a[i] << endl;
        string s;
        cin >> s;
        if (s == "Yes") {
            cout << "! " << a[i] << " " << a[j] << endl;
            return 0;
        }
    }
    cout << "! 0 0" << '\n';
    return 0;
}