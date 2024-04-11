#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector<int> col;
    for(int j = 1; j < m; ++j) {
        for(int i = 0; i + 1 < n; ++i) {
            if(g[i][j] == 'X' && g[i + 1][j - 1] == 'X') {
                col.push_back(j);
                break;
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if(upper_bound(col.begin(), col.end(), r) != upper_bound(col.begin(), col.end(), l)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}