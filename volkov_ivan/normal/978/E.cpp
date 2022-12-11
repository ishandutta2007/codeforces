#include <iostream>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, w;
    cin >> n >> w;
    int l = 0, r = w, d, diff = 0;
    for (int i = 0; i < n; i++) {
        cin >> d;
        diff += d;
        if (w - diff < r) {
            r = w - diff;
        }
        if (-diff > l) {
            l = -diff;
        }
    }
    if (r < l) cout << 0 << endl;
    else cout << r - l + 1 << endl;
    return 0;
}