#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    cout << N + 1 << endl;
    // N+1

    cout << 1 << " " << N << " " << 500000 << endl;
    // 500000

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        a += 500000;

        // ai
        // aa - i
        cout << 2 << " " << i + 1 << " " << a - i << endl;
    }
    return 0;
}