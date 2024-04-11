#include <bits/stdc++.h>
using namespace std;

int k, pos0, n;

int ask(const string& s) {
    cout << "? " << s << endl;
    int h; cin >> h;
    return h;
}

int bs(int l, int r, int now, int dt, string s) {
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    string t = s;
    for (int i = l; i < r; ++i) t[i] = '0';
    for (int i = l; i < m; ++i) t[i] = '1';
    int h = ask(t); h -= dt;
    int len = m - l;
    int o = (h + now - len) / 2;
    if (o == 0) {
        pos0 = m;
        return bs(l, m, now - o, dt + o, t);
    } else if (o == r - m && now > o) {
        return bs(l, m, now - o, dt + o, t);
    } else if (o == now) {
        pos0 = l;
        return bs(m, r, o, dt + len - now + o, t);
    } else {
        return bs(m, r, o, dt + len - now + o, t);
    }
}

int cnt[2];

int main() {
    srand(time(nullptr));
    cin >> n;
    pos0 = -1;
    string s; 
    for (int i = 0; i < n; ++i) s += '0';
    k = ask(s);
    int pos1 = bs(0, n, k, 0, s);
    for (int i = 0; i < n; ++i) s[i] = '1';
    cout << "! " << pos0 + 1 << ' ' << pos1 + 1 << endl;
    return 0;
}