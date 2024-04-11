#include <bits/stdc++.h>
using namespace std;

vector<int> sz, par;
int ct;

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}

void unite(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) {
        --ct;
        if (sz[i] > sz[j]) {
            swap(i, j);
        }
        par[i] = j;
        sz[j] += sz[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> freq(26);
    for (int j = 0; j < n; ++j) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; ++i) {
            if (find(s.begin(), s.end(), 'a' + i) != s.end()) {
                freq[i].push_back(j);
            }
        }
    }

    sz.assign(n, 1);
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    ct = n;
    for (auto& i : freq) {
        if (i.size() <= 1) continue;
        for (auto j : i) {
            unite(j, i[0]);
        }
    }
    cout << ct << '\n';
}