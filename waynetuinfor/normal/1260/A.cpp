#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int c, s; cin >> c >> s;
        int x = (s / c) * (s / c);
        int y = (s / c + 1) * (s / c + 1);
        cout << 1LL * x * (c - s % c) + 1LL * y * (s % c) << endl;
    }
}