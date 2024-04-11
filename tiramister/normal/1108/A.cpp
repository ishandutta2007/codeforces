#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int l[2], r[2];
        for (int i = 0; i < 2; ++i) {
            cin >> l[i] >> r[i];
        }

        bool swapped = false;
        if (r[0] - l[0] > r[1] - l[1]) {
            swap(l[0], l[1]);
            swap(r[0], r[1]);
            swapped = true;
        }

        int ans[2] = {l[0], l[1]};
        if (ans[0] == ans[1]) ++ans[1];

        if (swapped) swap(ans[0], ans[1]);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}