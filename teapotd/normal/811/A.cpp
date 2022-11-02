#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    bool flip = 0;

    for (int k = 1; k <= a; k++) {
        a -= k;
        swap(a, b);
        flip = !flip;
    }

    cout << (flip ? "Valera\n" : "Vladik\n");
    return 0;
}