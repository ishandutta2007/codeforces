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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (a.size() >= 4) {
        vector<vector<int>> b(4);
        int sz = (int) a.size();
        for (int i = 0; i < sz; i++) {
            b[i % 4].emplace_back(a[i]);
        }
        vector<string> d;
        for (int z = 0; z < 2; z++) {
            vector<int> c;
            if (z == 0) {
                c = b[0];
            } else {
                c = b[2];
            }
            c.insert(c.end(), b[1].begin(), b[1].end());
            sort(c.begin(), c.end());
            cout << "? " << c.size();
            for (int i : c) {
                cout << " " << i;
            }
            cout << endl;
            string t;
            cin >> t;
            d.emplace_back(t);
        }
        if (d[0] == "YES" && d[1] == "YES") {
            b[3].clear();
        } else if (d[0] == "YES" && d[1] == "NO") {
            b[2].clear();
        } else if (d[0] == "NO" && d[1] == "YES") {
            b[0].clear();
        } else {
            b[1].clear();
        }
        a.clear();
        for (int i = 0; i < 4; i++) {
            a.insert(a.end(), b[i].begin(), b[i].end());
        }
    }
    if (a.size() == 1) {
        cout << "! " << a[0] << endl;
        string z;
        cin >> z;
        assert(z == ":)");
    } else if (a.size() == 2) {
        cout << "! " << a[0] << endl;
        string z;
        cin >> z;
        if (z == ":(") {
            cout << "! " << a[1] << endl;
            cin >> z;
            assert(z == ":)");
        }
    } else {
        cout << "? 1 " << a[0] << endl;
        string z;
        cin >> z;
        if (z == "YES") {
            cout << "? 1 " << a[1] << endl;
            cin >> z;
            if (z == "YES") {
                a.erase(a.begin() + 2);
            } else {
                a.erase(a.begin() + 1);
            }
        } else {
            cout << "? 1 " << a[1] << endl;
            cin >> z;
            if (z == "YES") {
                a.erase(a.begin());
            } else {
                cout << "? 1 " << a[1] << endl;
                cin >> z;
                if (z == "YES") {
                    cout << "? 1 " << a[0] << endl;
                    cin >> z;
                    if (z == "YES") {
                        a.erase(a.begin() + 2);
                    } else {
                        a.erase(a.begin());
                    }
                } else {
                    a.erase(a.begin() + 1);
                }
            }
        }
        cout << "! " << a[0] << endl;
        cin >> z;
        if (z == ":(") {
            cout << "! " << a[1] << endl;
            cin >> z;
            assert(z == ":)");
        }
    }
    return 0;
}