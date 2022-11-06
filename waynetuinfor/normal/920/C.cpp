#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    string s; cin >> s;
    int pos = 0;
    while (pos < n - 1) {
        if (s[pos] == '0') {
            ++pos;
            continue;
        }
        int to = pos;
        while (to < n - 1 && s[to] == '1') ++to;
        sort(a + pos, a + to + 1);
        pos = to;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
}