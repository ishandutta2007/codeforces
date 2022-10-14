#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
    int X, Y; cin >> X >> Y;
    int dif_X = abs(X1 - X2), dif_Y = abs(Y1 - Y2);
    cout << (dif_X % X == 0 && dif_Y % Y == 0 && (dif_X / X) % 2 == (dif_Y / Y) % 2 ? "YES" : "NO") << '\n';
    return 0;
}