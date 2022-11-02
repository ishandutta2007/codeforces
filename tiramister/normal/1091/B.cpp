#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll sum[2];
    sum[0] = sum[1] = 0;
    for (int i = 0; i < N * 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ll x;
            cin >> x;
            sum[j] += x;
        }
    }

    cout << sum[0] / N << " " << sum[1] / N << endl;
    return 0;
}