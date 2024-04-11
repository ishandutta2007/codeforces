#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int m1 = 1, m2 = 2;
    while (true) {
        if (a < m1) return cout << "Vladik\n", 0;
        a -= m1;
        if (b < m2) return cout << "Valera\n", 0;
        b -= m2;
        m1 += 2; m2 += 2;
    }
    return 0;
}