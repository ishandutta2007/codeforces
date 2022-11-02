#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N, S;
    cin >> N >> S;

    ll sum = 0, mi = 1 << 30;
    for (int i = 0; i < N; ++i) {
        ll v;
        cin >> v;
        sum += v;
        mi = min(mi, v);
    }

    cout << (sum < S ? -1 : min(mi, (sum - S) / N)) << endl;
    return 0;
}