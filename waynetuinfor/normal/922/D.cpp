#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

long long cal(const string &st) {
    long long ret = 0, s = 0;
    for (int i = 0; i < st.size(); ++i) {
        if (st[i] == 's') ++s;
        else ret += s;
    }
    return ret;
}

int main() {
    int n; cin >> n;
    vector<string> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end(), [](const string &a, const string &b) { return cal(a + b) > cal(b + a); }); 
    // reverse(t.begin(), t.end());
    string fin = "";
    for (int i = 0; i < n; ++i) fin += t[i];
    // reverse(fin.begin(), fin.end());
    long long ans = 0, s = 0;
    // cout << fin << endl;
    for (int i = 0; i < fin.size(); ++i) {
        if (fin[i] == 's') ++s;
        else ans += s;
    }
    cout << ans << endl;
}