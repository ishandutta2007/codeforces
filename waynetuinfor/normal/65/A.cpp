#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (b * d * f > a * c * e) return cout << "Ron" << endl, 0;
    if (d == 0) cout << "Hermione" << endl;
    else if (c == 0) cout << "Ron" << endl;
    else if (b == 0) cout << "Hermione" << endl;
    else if (a == 0) cout << "Ron" << endl;
    else if (f == 0) cout << "Hermione" << endl;
    else if (e == 0) cout << "Ron" << endl;
    else cout << "Hermione" << endl;
}