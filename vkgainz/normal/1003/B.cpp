 
#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int a, b, x; cin >> a >> b >> x;
    if (x == 2 * min(a, b)) {
        if (a < b) {
            for (int i = 1; i <= x / 2; i++) {
                cout << "10";
            }
            for (int i = 1; i <= b - a; i++) {
                cout << "1";
            }
        } else {
            for (int i = 1; i <= x / 2; i++) {
                cout << "01";
            }
            for (int i = 1; i <= a - b; i++) {
                cout << "0";
            }
        }
        return 0;
    }
    if (x % 2 == 0) {
        int lim = x / 2;
        for (int i = 0; i < 2 * lim; i++) {
            if (i % 2 == 0) {
                cout << "0"; 
            } else {
                cout << "1";
            }
        }
        for (int i = lim + 1; i <= b; i++) {
            cout << "1";
        }
        for (int i = lim + 1; i <= a; i++) {
            cout << "0";
        }
    } else {
        int lim = x / 2;
        for (int i = 0; i < 2 * lim; i++) {
            if (i % 2 == 0) {
                cout << "0"; 
            } else {
                cout << "1";
            }
        }
        for (int i = lim + 1; i <= a; i++) {
            cout << "0";
        }
        for (int i = lim + 1; i <= b; i++) {
            cout << "1";
        }
    }
}