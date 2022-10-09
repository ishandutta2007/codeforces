#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n >> m;
        if (n % 2 == 1 && m % 2 == 1) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if ((i + j) % 2 == 0) {
                        cout << 'B';
                    } else {
                        cout << 'W';
                    }
                }
                cout << endl;
            }
        } else {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if ((i + j) % 2 == 0 && (i + j) != 0) {
                        cout << 'W';
                    } else {
                        cout << 'B';
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}