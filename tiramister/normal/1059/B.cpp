#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string S[N];
    for (int x = 0; x < N; ++x) cin >> S[x];

    string T[N];
    fill(T, T + N, string(M, '.'));

    for (int x = 1; x < N - 1; ++x) {
        for (int y = 1; y < M - 1; ++y) {
            bool paint = true;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    if (S[x + dx][y + dy] == '.') paint = false;
                }
            }

            if (!paint) continue;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    T[x + dx][y + dy] = '#';
                }
            }
        }
    }

    for (int x = 0; x < N; ++x) {
        if (S[x] != T[x]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}