#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int t[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
string s[maxn];
bool nz[maxn];
long long v[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        nz[s[i][0]] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = s[i].size() - 1; j >= 0; --j) v[s[i][j]] += t[s[i].size() - 1 - j];
    }
    vector<char> o(10); iota(o.begin(), o.end(), 'a');
    sort(o.begin(), o.end(), [&](const char &i, const char &j) { return v[i] > v[j]; });
    // for (char c : o) cout << c << ' '; cout << endl;
    int p = 0;
    while (p < o.size() && nz[o[p]]) ++p;
    // cout << "op = " << o[p] << endl;
    vector<char> oo;
    for (char c = 'a'; c <= 'j'; ++c) if (c != o[p]) oo.push_back(c);
    sort(oo.begin(), oo.end(), [&](const char &i, const char &j) { return v[i] > v[j]; });
    long long ans = 0;
    for (int i = 1; i <= 9; ++i) ans += i * 1ll * v[oo[i - 1]];
    cout << ans << endl;
    return 0;
}