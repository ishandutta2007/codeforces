#include <bits/stdc++.h>
using namespace std;

int points(int p, int t) {
    return max(3 * p / 10, p - p / 250 * t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (points(a, c) == points(b, d)) {
        cout << "Tie\n";
    } else if (points(a, c) > points(b, d)) {
        cout << "Misha\n";
    } else {
        cout << "Vasya\n";
    }
}