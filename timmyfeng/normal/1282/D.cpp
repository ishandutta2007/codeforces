#include <bits/stdc++.h>
using namespace std;

int query(string t) {
    cout << t << endl;
    int ret;
    cin >> ret;
    if (!ret) exit(0);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cta = 300 - query(string(300, 'a'));
    int ctb = 300 - query(string(300, 'b'));
    int sz = cta + ctb;
    string t(sz, 'a');
    for (int i = 0; i < sz - 1; i++) {
        t[i] = 'b';
        if (query(t) >= ctb) {
            t[i] = 'a';
        } else {
            --ctb;
        }
    }
    if (ctb) {
        t.back() = 'b';
    }
    cout << t << "\n";
}