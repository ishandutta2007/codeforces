#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x1, p1; cin >> x1 >> p1;
        int x2, p2; cin >> x2 >> p2;
        int lg1 = 0, lg2 = 0;
        int tmp = x1;
        while (tmp) {
            ++lg1;
            tmp /= 10;
        } 
        tmp = x2;
        while (tmp) {
            ++lg2;
            tmp /= 10;
        }
        if (p1 + lg1 == p2 + lg2) {
            for (int i = p1; i < p2; i++) {
                x2 *= 10;
            }
            for (int i = p2; i < p1; i++) {
                x1 *= 10;
            }
            if (x1 == x2) {
                cout << "=" << "\n";
            } else if (x1 < x2) {
                cout << "<" << "\n";
            } else {
                cout << ">" << "\n";   
            }
        } else if (p1 + lg1 > p2 + lg2) {
            cout << ">" << "\n";
        } else {
            cout << "<" << "\n";
        }
    }
}