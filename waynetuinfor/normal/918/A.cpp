#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;
bool v[maxn];

int main() {
    int n; cin >> n;
    vector<int> f = { 1, 1 };
    while (f.back() < n) {
        f.push_back(f[f.size() - 2] + f[f.size() - 1]);
    }
    for (int i : f) v[i] = true;
    for (int i = 1; i <= n; ++i) {
        if (v[i]) cout << 'O';
        else cout << 'o';
    }
    return 0;
}