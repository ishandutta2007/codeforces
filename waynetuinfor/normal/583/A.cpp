#include <bits/stdc++.h>
using namespace std;

bool a[100], b[100];

int main() {
    int n; cin >> n;
    vector<int> ans;
    for (int i = 0; i < n * n; ++i) {
        int h, v; cin >> h >> v;
        if (!a[h] && !b[v]) ans.push_back(i + 1), a[h] = b[v] = true;
    }
    for (int i : ans) cout << i << ' '; 
}