#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, p = 199, mod = 370248451;

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

int ps(const string& s) {
    stringstream ss(s);
    int ret; ss >> ret;
    return ret;
}

vector<pair<int, char>> va, vb, na;
int f[maxn], ppow[maxn], ha[maxn], hb[maxn];

int get(pair<int, char> pr) {
    return add(mul(pr.first % mod, 35317), pr.second);
}

void init() {
    ppow[0] = 1;
    for (int i = 1; i < maxn; ++i) ppow[i] = mul(ppow[i - 1], p);
    ha[0] = get(na[0]);
    for (int i = 1; i < na.size(); ++i) ha[i] = add(mul(ha[i - 1], p), get(na[i]));
    hb[0] = get(vb[0]);
    for (int i = 1; i < vb.size(); ++i) hb[i] = add(mul(hb[i - 1], p), get(vb[i]));
}

bool check(int l, int r) {
    int hs = -1;
    if (l == 0) hs = hb[r];
    else hs = sub(hb[r], mul(ppow[r - l + 1], hb[l - 1]));
    return hs == ha[na.size() - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int l = ps(s.substr(0, s.length() - 2)), c = s[s.length() - 1];
        if (va.size() && va.back().second == c) va.back().first += l;
        else va.push_back(make_pair(l, c));
    }
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        int l = ps(s.substr(0, s.length() - 2)), c = s[s.length() - 1];
        if (vb.size() && vb.back().second == c) vb.back().first += l;
        else vb.push_back(make_pair(l, c));
    }
    swap(va, vb);
    if (va.size() == 1) {
        int ans = 0;
        for (auto i : vb) {
            if (i.second == va[0].second) ans += max(i.first - va[0].first + 1, 0ll);
        }
        cout << ans << endl;
        return 0;
    }
    if (va.size() == 2) {
        int ans = 0;
        for (int i = 0; i < vb.size() - 1; ++i) {
            if (vb[i].second == va[0].second && vb[i].first >= va[0].first &&
                vb[i + 1].second == va[1].second && vb[i + 1].first >= va[1].first) ++ans;
        }
        cout << ans << endl;
        return 0;
    }
    na = vector<pair<int, char>>(va.begin() + 1, va.end() - 1);
    init();
    vector<int> res;
    for (int i = 0; i < vb.size(); ++i) {
        if (i + na.size() > vb.size()) break;
        if (check(i, i + na.size() - 1)) res.push_back(i);
    }
    int ans = 0;
    for (int i : res) {
        if (i > 0 && i + na.size() < vb.size()) {
            if (vb[i - 1].second == va[0].second && vb[i - 1].first >= va[0].first && 
                vb[i + na.size()].second == va[va.size() - 1].second && vb[i + na.size()].first >= va[va.size() - 1].first) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}