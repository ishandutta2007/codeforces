#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], n;
map<char, int> p;

int parse(char c) {
    if (p.find(c) != p.end()) return p[c];
    p[c] = p.size();
    return p[c];
}

bool check(int now) {
    // cout << "now = " << now << endl;
    vector<int> c(p.size() + 1, 0);
    int e = p.size();
    for (int i = 0; i < now - 1; ++i) {
        if (c[a[i]] == 0) --e;
        ++c[a[i]];
    }
    for (int i = now - 1; i < n; ++i) {
        if (c[a[i]] == 0) --e;
        ++c[a[i]];
        if (e == 0) return true;
        --c[a[i - now + 1]];
        if (c[a[i - now + 1]] == 0) ++e;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) a[i] = parse(s[i]);
    int d = 20, ans = n; while (d--) if (ans - (1 << d) >= 1) if (check(ans - (1 << d))) ans -= (1 << d);
    cout << ans << endl;
    return 0;
}