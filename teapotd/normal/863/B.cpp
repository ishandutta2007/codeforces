#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    n *= 2;
    vector<int> elems(n);

    for (int& x : elems) {
        cin >> x;
    }

    int ans = INT_MAX;
    sort(elems.begin(), elems.end());

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int last = -1, alt = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    if (last != -1) {
                        alt += elems[k] - last;
                        last = -1;
                    } else {
                        last = elems[k];
                    }
                }
            }
            ans = min(ans, alt);
        }
    }

    cout << ans << endl;
    return 0;
}