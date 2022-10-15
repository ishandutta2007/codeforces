#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

string solve() {
    int n;
    cin >> n;

    string s[3];
    for (auto& x : s) cin >> x;

    map<char, int> freq[3];
    for (int t = 0; t < 3; ++t) {
        for (auto c : s[t]) freq[t][c] += 1;
    }

    int x = -1, y = -1;
    char d[2] = { '0', '1' };
    for (int t = 0; t < 3 && x == -1; ++t) {
        for (int s = t + 1; s < 3 && x == -1; ++s) {
            for (auto c : {'0', '1'}) {
                if (min(freq[t][c], freq[s][c]) >= n) {
                    if (d[0] != c) swap(d[0], d[1]);
                    x = t, y = s;
                    break;
                }
            }
        }
    }

    string res;

    int i = 0, j = 0;
    while (i < 2 * n && j < 2 * n) {
        res.push_back(s[x][i] == s[y][j] ? s[x][i] : d[1]);
        if (s[x][i] == res.back()) ++i;
        if (s[y][j] == res.back()) ++j;
    }
    res += s[x].substr(i, n);
    res += s[y].substr(j, n);

    res.resize(3 * n, '0');
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}