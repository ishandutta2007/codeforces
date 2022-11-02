#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll w[2], h[2];
    for (int i = 0; i < 2; ++i) cin >> w[i] >> h[i];

    ll W = w[0], H = h[0] + h[1];
    cout << (W + 2) * (H + 2) - W * H << endl;
    return 0;
}