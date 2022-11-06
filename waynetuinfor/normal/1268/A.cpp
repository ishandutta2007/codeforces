#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t = s;
    for (int i = 0; i < n; ++i) {
        if (i + k < n && t[i + k] != t[i]) t[i + k] = t[i];
    }
    if (t >= s) {
        cout << t.size() << endl;
        cout << t << endl;
        return 0;
    }
    bool ok = false;
    for (int i = k - 1; i >= 0; --i) {
        if (s[i] != '9') {
            ok = true;
            s[i]++;
            for (int j = i + 1; j < k; ++j) s[j] = '0';
            break;
        }
    }
    if (!ok) s = "1" + s;
    t = s;
    for (int i = 0; i < n; ++i) {
        if (i + k < n && t[i + k] != t[i]) t[i + k] = t[i];
    }
    cout << t.size() << endl;
    cout << t << endl;
}