#include <bits/stdc++.h>
using namespace std;
 
const int N = 250000;
 
vector<int> arrays[N];
int n, m;
 
void solve(int k) {
    if (k > 2) {
        return;
    }
 
    for (int i = 1; i < n; ++i) {
        int delta = 0;
        for (int j = 0; j < m; ++j) {
            delta += arrays[0][j] != arrays[i][j];
        }
 
        if (delta + k > 4) {
            return;
        } else if (delta > 2) {
            for (int j = 0; j < m; ++j) {
                if (arrays[0][j] != arrays[i][j]) {
                    int prv = arrays[0][j];
                    arrays[0][j] = arrays[i][j];
                    solve(k + 1);
                    arrays[0][j] = prv;
                }
            }
            return;
        }
    }
 
    cout << "Yes\n";
    for (auto i : arrays[0]) {
        cout << i << " ";
    }
    cout << "\n";
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; ++i) {
        arrays[i].resize(m);
        for (auto &j : arrays[i]) {
            cin >> j;
        }
    }
 
    solve(0);
 
    cout << "No\n";
}