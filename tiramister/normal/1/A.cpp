#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    ll N, M, A;
    cin >> N >> M >> A;
    cout << iceil(N, A) * iceil(M, A) << endl;
    return 0;
}