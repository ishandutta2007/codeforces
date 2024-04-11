#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    ll sum = 0;

    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + N);

    ll h = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] > h) ++h;
    }

    cout << sum - (N + a[N - 1] - h) << endl;
    return 0;
}