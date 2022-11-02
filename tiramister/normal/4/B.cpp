#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int D, sum;
    cin >> D >> sum;
    int l[D], r[D];
    for (int d = 0; d < D; ++d) {
        cin >> l[d] >> r[d];
    }

    if (sum < accumulate(l, l + D, 0) || accumulate(r, r + D, 0) < sum) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    int diff = sum - accumulate(l, l + D, 0);
    for (int d = 0; d < D; ++d) {
        while (diff > 0 && l[d] < r[d]) {
            ++l[d];
            --diff;
        }
    }

    for (int d = 0; d < D; ++d) cout << l[d] << " ";
    cout << endl;
    return 0;
}