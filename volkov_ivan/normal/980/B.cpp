#include <iostream>
 
using namespace std;

const int MAX_N = 100;
char field[4][MAX_N];

void print(int n) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j] = '.';
        }
    }
    cout << "YES" << endl;
    if (k % 2 == 0) {
        for (int i = 0; i < k / 2; i++) {
            field[1][i + 1] = field[2][i + 1] = '#';
        }
        print(n);
        return 0;
    }
    if (k == 1) {
        field[1][n / 2] = '#';
        print(n);
        return 0;
    }
    if (k == 3) {
        field[1][n / 2 - 1] = field[1][n / 2] = field[1][n / 2 + 1] = '#';
        print(n);
        return 0;
    }
    field[1][1] = field[2][1] = field[1][2] = field[1][3] = field[2][3] = '#';
    k -= 5;
    for (int i = 0; i < k / 2; i++) {
        field[1][i + 4] = field[2][i + 4] = '#';
    }
    print(n);
    return 0;
}