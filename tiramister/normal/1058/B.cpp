#include <iostream>

using namespace std;

int main() {
    int N, D, M;
    cin >> N >> D >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        int u = x + y, v = x - y;
        cout << (D <= u && u <= N * 2 - D && -D <= v && v <= D ? "YES" : "NO") << endl;
    }
    return 0;
}