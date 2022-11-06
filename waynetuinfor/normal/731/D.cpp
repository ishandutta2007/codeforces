#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> hyp[maxn];
int s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c; cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        hyp[i].resize(l);
        for (int j = 0; j < l; ++j) cin >> hyp[i][j];
    }
    for (int i = 0; i < n - 1; ++i) {
        size_t ptr = 0;
        while (ptr < min(hyp[i].size(), hyp[i + 1].size())) {
            if (hyp[i][ptr] != hyp[i + 1][ptr]) break;
            ++ptr;
        }
        if (ptr == min(hyp[i].size(), hyp[i + 1].size())) {
            if (hyp[i].size() > hyp[i + 1].size()) return cout << "-1" << endl, 0;
            ++s[0]; --s[c];
            continue;
        }
        if (hyp[i][ptr] < hyp[i + 1][ptr]) ++s[0], --s[c - hyp[i + 1][ptr] + 1], ++s[c - hyp[i][ptr] + 1], --s[c];
        else ++s[c - hyp[i][ptr] + 1], --s[c - hyp[i + 1][ptr] + 1];
    }
    for (int i = 1; i <= c; ++i) s[i] += s[i - 1];
    for (int i = 0; i <= c - 1; ++i) {
        if (s[i] == n - 1) return cout << i << endl, 0;
    }
    cout << "-1" << endl;
    return 0;
}