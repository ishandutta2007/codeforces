#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;

        if (a > b) {
            swap(a, b);
        }

        bool magic = false;
        while (a > 0) {
            magic |= x <= b && x % a == b % a;
            b %= a;
            swap(a, b);
        }

        cout << (magic ? "YES" : "NO") << "\n";
    }
}