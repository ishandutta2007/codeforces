#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) if (n % i == 0) if (check(i)) return cout << "YES" <<endl, 0;
    cout << "NO" << endl;
    return 0;
}