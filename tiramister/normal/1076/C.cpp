#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << fixed << setprecision(10);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int d;
        cin >> d;
        if (0 < d && d < 4) {
            cout << "N";
        } else {
            cout << "Y ";
            long double r = sqrt(d * (d - 4));
            cout << (d + r) / 2 << " " << (d - r) / 2;
        }
        cout << endl;
    }
    return 0;
}