#include <iostream>

using namespace std;

// 
int question(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    int c = 0, d = 0;

    // c, da^cb^d
    int stat = question(c, d);

    for (int k = 29; k >= 0; --k) {
        int ret = question(c + (1 << k), d + (1 << k));

        if (ret == stat) {
            //  = k

            //
            int ret = question(c, d + (1 << k));
            if (ret == 1) {
                c += (1 << k);
                d += (1 << k);
            }
            // stat

        } else {
            //  = k
            // 1
            if (stat == 1) {
                c += (1 << k);
            } else {
                d += (1 << k);
            }

            // stat
            stat = question(c, d);
        }
    }

    cout << "! " << c << " " << d << endl;
    return 0;
}