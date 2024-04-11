#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    cout << m * n + m + n - 3 << endl;
    for (i = 0; i < n - 1; i++) {
        cout << "U";
    }
    for (i = 0; i < m - 1; i++) {
        cout << "L";
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - 1; j++) {
            if (i % 2 == 0) {
                cout << "D";
            } else {
                cout << "U";
            }
        }
        if (i != m - 1) {
            cout << "R";
        }
    }

    return 0;
}