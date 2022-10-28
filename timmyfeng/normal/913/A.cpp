#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n < 32) {
        cout << m % (1 << n) << "\n";
    } else {
        cout << m << "\n";
    }
}