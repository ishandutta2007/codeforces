#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    if (N % 2 == 0) {
        cout << N / 2 << endl;
        return 0;
    }

    for (ll p = 2; p * p <= N; ++p) {
        if (N % p == 0) {
            cout << (N - p) / 2 + 1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}