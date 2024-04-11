#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll N, A, B;
        cin >> N >> A >> B;
        cout << (A * 2 <= B ? N * A : (N / 2) * B + (N % 2) * A) << endl;
    }
    return 0;
}