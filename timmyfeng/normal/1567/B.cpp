#include <bits/stdc++.h>
using namespace std;

const int N = 300001;

int prefix[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i < N; ++i) {
        prefix[i] = prefix[i - 1] ^ i;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        if ((prefix[a - 1] ^ b) == a) {
            cout << a + 2 << "\n";
        } else if (prefix[a - 1] != b) {
            cout << a + 1 << "\n";
        } else {
            cout << a << "\n";
        }
    }
}