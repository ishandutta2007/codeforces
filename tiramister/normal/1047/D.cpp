#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    if (N > M) swap(N, M);
    ll rem = 0;
    if (N == 1) {
        rem = min(M % 6, 6 - M % 6);
    } else {
        if (N % 2 == 1 && M % 2 == 1) {
            rem = 1;
        } else {
            if (M == 2) {
                rem = 4;
            } else if (M == 3 || M == 7) {
                rem = 2;
            } else {
                rem = 0;
            }
        }
    }

    cout << N * M - rem << endl;
    return 0;
}