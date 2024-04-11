#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 0, cnt = 0;
    bool found = false;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;

        int giv = min(8, sum);
        cnt += giv;
        sum -= giv;

        if (cnt >= k) {
            cout << i;
            found = true;
            break;
        }
    }

    if (!found) cout << -1;
}