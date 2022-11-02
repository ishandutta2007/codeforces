#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    ll a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);

    ll ok = N + 1, ng = 0;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        ll cnt = 0, d = 0, sum = 0;

        for (int i = N - 1; i >= 0; --i) {
            if (a[i] <= d) break;
            sum += a[i] - d;
            ++cnt;
            if (cnt == mid) {
                ++d;
                cnt = 0;
            }
        }

        if (sum >= M) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << (ok > N ? -1 : ok) << endl;
    return 0;
}