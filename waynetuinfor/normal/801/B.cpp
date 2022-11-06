#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string x, y; cin >> x >> y;
    string z = "";
    for (int i = 0; i < x.length(); ++i) {
        if (x[i] >= y[i]) z += y[i];
        else return cout << "-1\n", 0;
    }
    cout << z << '\n';
    return 0;
}