#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int k = 1;
    for (int i = 2; i <= n; ++i) {
        if ((n - 1) / i + i < (n - 1) / k + k) {
            k = i;
        }
    }

    int ptr = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = n / k + (i < n % k); j > 0; --j) {
            cout << ptr + j << " ";
        }
        ptr += n / k + (i < n % k);
    }
    cout << "\n";
}