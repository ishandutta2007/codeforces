#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;
long double lg[20];

bool equal(const long double &a, const long double &b) { return a > b - eps && a < b + eps; }

int main() {
    long double x, y, z; cin >> x >> y >> z;
    {
        lg[1] = pow(y, z) * log(x);
        lg[2] = pow(z, y) * log(x);
        lg[3] = y * z * log(x);
        lg[4] = z * y * log(x);
    }
    {
        lg[5] = pow(x, z) * log(y);
        lg[6] = pow(z, x) * log(y);
        lg[7] = x * z * log(y);
        lg[8] = z * x * log(y);
    }
    {
        lg[9] = pow(x, y) * log(z);
        lg[10] = pow(y, x) * log(z);
        lg[11] = x * y * log(z);
        lg[12] = y * x * log(z);
    }
    long double ans = -100000000000.0000; int bst = -1;
    for (int i = 1; i <= 12; ++i) {
        if (!(equal(lg[i], ans)) && lg[i] > ans) {
            ans = lg[i];
            bst = i;
        }
    }
    assert(bst >= 1 && bst <= 12);
    if (bst == 1) cout << "x^y^z" << endl;
    if (bst == 2) cout << "x^z^y" << endl;
    if (bst == 3) cout << "(x^y)^z" << endl;
    if (bst == 4) cout << "(x^z)^y" << endl;
    if (bst == 5) cout << "y^x^z" << endl;
    if (bst == 6) cout << "y^z^x" << endl;
    if (bst == 7) cout << "(y^x)^z" << endl;
    if (bst == 8) cout << "(y^z)^x" << endl;
    if (bst == 9) cout << "z^x^y" << endl;
    if (bst == 10) cout << "z^y^x" << endl;
    if (bst == 11) cout << "(z^x)^y" << endl;
    if (bst == 12) cout << "(z^y)^x" << endl;
}