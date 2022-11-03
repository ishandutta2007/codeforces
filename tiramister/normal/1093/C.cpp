#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll a[N + 1], b[N / 2 + 1];
    for (int i = 1; i <= N / 2; ++i) {
        cin >> b[i];
    }

    a[1] = 0, a[N] = b[1];

    for (int i = 2; i <= N / 2; ++i) {
        a[i] = a[i - 1];
        a[N - i + 1] = b[i] - a[i];
        if (a[N - i + 1] > a[N - i + 2]) {
            a[N - i + 1] = a[N - i + 2];
            a[i] = b[i] - a[N - i + 1];
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}