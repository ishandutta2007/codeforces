#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
string s[maxn];
bool vc[maxn], vr[maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    while (true) {
        int a = -1, b = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '#') {
                    a = i; b = j;
                    break;
                }
            }
        }
        if (a == -1) break;
        vector<int> col;
        memset(vc, false, sizeof(vc)); memset(vr, false, sizeof(vr));
        for (int c = 0; c < m; ++c) if (s[a][c] == '#') col.push_back(c), vc[c] = true;
        while (col.size() > 0) {
            vector<int> row;
            for (int c : col) {
                // cout << "c = " << c << endl;
                for (int r = 0; r < n; ++r) if (!vr[r] && s[r][c] == '#') row.push_back(r), vr[r] = true;
            }
            col.clear();
            for (int r : row) {
                // cout << "r = " << r << endl;
                for (int c = 0; c < m; ++c) if (!vc[c] && s[r][c] == '#') col.push_back(c), vc[c] = true;
            }
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (vr[r] && vc[c]) {
                    if (s[r][c] != '#') return cout << "No" << endl, 0;
                    s[r][c] = '.';
                }
            }
        }
    } 
    cout << "Yes" << endl;
    return 0;
}