#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;

    if (xp <= xv && yp <= yv) {
        cout << "Polycarp\n";
    } else if (xp >= xv && yp >= yv) {
        cout << "Vasiliy\n";
    } else {
        if (yp < yv) {
            swap(xp, yp), swap(xv, yv);
        }
        cout << (yp - (xv - xp) <= max(0, yv - (xv - xp)) ? "Polycarp" : "Vasiliy") << "\n";
    }
}