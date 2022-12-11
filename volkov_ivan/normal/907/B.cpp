#include <iostream>

using namespace std;

int main() {
    int x, y, xf, yf, xk, yk;
    char f[3][3][3][3];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            xf = i / 3;
            yf = j / 3;
            x = i % 3;
            y = j % 3;
            //cout << i << ' ' << j << ' ' << xf << ' ' << yf << ' ' << x << ' ' << y << endl;
            cin >> f[xf][yf][x][y];
        }
    }
    cin >> x >> y;
    x--;
    y--;
    xf = x % 3;
    yf = y % 3;
    bool coloured = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f[xf][yf][i][j] == '.') {
                f[xf][yf][i][j] = '!';
                coloured = 0;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            xf = i / 3;
            yf = j / 3;
            x = i % 3;
            y = j % 3;
            if (coloured && f[xf][yf][x][y] == '.') {
                f[xf][yf][x][y] = '!';
            }
            cout << f[xf][yf][x][y];
            if (j == 2 || j == 5) {
                cout << ' ';
            }
        }
        cout << endl;
        if (i == 2 || i == 5) {
            cout << endl;
        }
    }
    return 0;
}