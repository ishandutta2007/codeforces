// 1333D
// sostituzione RL con LR

#include <bits/stdc++.h>
using namespace std;

int i, i1, j, k, k1, t, n, m, res, check1, a, b, max1, x, y, w;
string s;
vector<int> v[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;
    cin >> s;

    max1 = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (s[j] == 'R' && s[j + 1] == 'L') {
                v[i].push_back(j);
                max1++;
                b = i;
            }
        }
        for (auto u : v[i]) {
            s[u] = 'L'; s[u + 1] = 'R';
        }
    }

    if (k < b || k > max1) {
        cout << -1;
        return 0;
    }

    check1 = 0;
    for (i = 1; i <= k; i++) {
        //cout << i << "\n";
        if (check1 == 0) {
            if (max1 - v[i].size() < k - i) {
                //cout << 111 << "\n";
                check1 = 1;
                j = max1 - k + i;
                y = j;
                x = i;
                cout << j << ' ';
                for (i1 = 0; i1 < j; i1++) {
                    cout << v[i][i1] + 1 << ' ';
                }
            } else {
                //cout << 112 << "\n";
                max1 -= v[i].size();
                cout << v[i].size() << ' ';
                for (auto u : v[i]) {
                    cout << u + 1 << ' ';
                }
            }
            cout << "\n";
        } else {
            //cout << 113 << "\n";
            if (v[x].size() == y) {
                x++;
                y = 0;
            }
            cout << 1 << ' ' << v[x][y] + 1 << "\n";
            y++;
        }
    }

    return 0;
}