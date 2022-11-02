#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    ll M, K;
    cin >> N >> M >> K;
    ll a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N, greater<ll>());

    cout << a[0] * M - (a[0] - a[1]) * (M / (K + 1)) << endl;
    return 0;
}