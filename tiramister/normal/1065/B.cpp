#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll mi = max(0LL, N - M * 2);
    ll ma = N;
    while (true) {
        ll c = N - ma;
        if (M <= c * (c - 1) / 2) break;
        --ma;
    }

    cout << mi << " " << ma << endl;
    return 0;
}