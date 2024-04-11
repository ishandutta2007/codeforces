#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    int a[n * k];
    for (int i = 0; i < n * k; i++) {
        cin >> a[i];
    }
    sort(a, a + n * k);
    int poss = 0, now = k, used = 0;
    for (int i = 0; i < n * k; i++) {
        if (a[i] - a[0] <= l) poss++;
        else break;
    }
    poss -= n;
    if (poss < 0) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < n * k; i++) {
        if (now < k && poss > 0) {
            now++;
            poss--;
            continue;
        }
        used++;
        now = 1;
        ans += a[i];
        if (used == n) break;
    }
    cerr << 3 << endl;
    cout << ans << endl;
    return 0;
}