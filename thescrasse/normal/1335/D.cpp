#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, b, d, mt[9][9];
string s[9];

void upd(int a, int b) {
    mt[a][b] = (mt[a][b] % 9) + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        for (i = 0; i < 9; i++) {
            cin >> s[i];
        }
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                mt[i][j] = (int)s[i][j] - 48;
            }
        }
        upd(0, 0);
        upd(3, 1);
        upd(6, 2);
        upd(1, 3);
        upd(4, 4);
        upd(7, 5);
        upd(2, 6);
        upd(5, 7);
        upd(8, 8);
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                cout << mt[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}