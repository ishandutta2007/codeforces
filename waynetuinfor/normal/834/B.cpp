#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
bool op[100], ok[100];
int l[100], r[100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < 26; ++i) l[i] = n + 1, r[i] = -1;
    for (int i = 0; i < s.length(); ++i) {
        l[s[i] - 'A'] = min(l[s[i] - 'A'], i);
        r[s[i] - 'A'] = max(r[s[i] - 'A'], i);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur > k) return cout << "YES" << endl, 0;
        for (int j = 0; j < 26; ++j) {
            if (l[j] != n + 1 && i == l[j]) ++cur;
            if (r[j] != -1 && i == r[j] + 1) --cur;
        } 
    }
    if (cur > k) return cout << "YES" << endl, 0;
    cout << "NO" << endl;
    return 0;
}