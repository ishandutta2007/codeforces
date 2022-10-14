#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    if (a1 >= (a2 + a3) && b1 >= max(b2, b3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (a2 + b3) && b1 >= max(b2, a3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (b2 + a3) && b1 >= max(a2, b3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (b2 + b3) && b1 >= max(a2, a3)) {
        cout << "YES" << '\n';
        return 0;
    }
    swap(a1, b1);
    if (a1 >= (a2 + a3) && b1 >= max(b2, b3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (a2 + b3) && b1 >= max(b2, a3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (b2 + a3) && b1 >= max(a2, b3)) {
        cout << "YES" << '\n';
        return 0;
    }
    if (a1 >= (b2 + b3) && b1 >= max(a2, a3)) {
        cout << "YES" << '\n';
        return 0;
    }
    cout << "NO" << '\n';
    return 0;
}