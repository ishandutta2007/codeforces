#include <iostream>

using namespace std;
using ll = long long;

int digsum(ll n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    ll N;
    cin >> N;

    ll A = 0, ten = 1;
    for (int i = 0; i < 15; ++i) {
        if (ten * 9 <= N) {
            A += ten * 9;
            N -= ten * 9;
        }
        ten *= 10;
    }

    cout << digsum(A) + digsum(N) << endl;
    return 0;
}