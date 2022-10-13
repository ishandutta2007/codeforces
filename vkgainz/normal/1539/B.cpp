#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<long long> p(n + 1);
    p[0] = 1LL;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1];
        p[i] += (s[i - 1] - 'a' + 1);
    }
    while(q--) {
        int l, r; cin >> l >> r;
        cout << p[r] - p[l - 1] << "\n";
    }
}