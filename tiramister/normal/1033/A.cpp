#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int x[3], y[3];
    for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];

    int dx[2], dy[2];
    for (int i = 1; i < 3; ++i) {
        dx[i - 1] = x[i] - x[0];
        dy[i - 1] = y[i] - y[0];
    }

    cout << (dx[0] * dx[1] > 0 && dy[0] * dy[1] > 0 ? "YES" : "NO") << endl;
    return 0;
}