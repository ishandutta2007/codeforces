#include <iostream>

using namespace std;

const int MAX_N = 100;
char field[MAX_N][MAX_N];

bool correct(int i, int j, int n, int m) {
    return (i < n && i >= 0 && j < m && j >= 0);
}

bool check(int i, int j, int n, int m) {
    if (field[i][j] == '*') return 1;
    if (field[i][j] == '.') field[i][j] = '0';
    int c1 = field[i][j] - '0', c2 = 0;
    for (int i1 = -1; i1 <= 1; i1++) {
        for (int j1 = -1; j1 <= 1; j1++) {
            if (i1 == 0 && j1 == 0) continue;
            if (correct(i + i1, j + j1, n, m) && field[i + i1][j + j1] == '*') c2++;
        }
    }
    return (c1 == c2);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!check(i, j, n, m)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}