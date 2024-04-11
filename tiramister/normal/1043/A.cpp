#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0, ma = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
        ma = max(ma, a);
    }

    for (int k = ma; k < 10000; ++k) {
        if (k * N - sum > sum) {
            cout << k << endl;
            break;
        }
    }
    return 0;
}