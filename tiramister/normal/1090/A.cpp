#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll M[N], ma[N];
    for (int i = 0; i < N; ++i) {
        cin >> M[i];
        ma[i] = 0;
        for (int j = 0; j < M[i]; ++j) {
            ll m;
            cin >> m;
            ma[i] = max(ma[i], m);
        }
    }

    ll ans = 0, sma = *max_element(ma, ma + N);
    for (int i = 0; i < N; ++i) {
        ans += M[i] * (sma - ma[i]);
    }

    cout << ans << endl;
    return 0;
}