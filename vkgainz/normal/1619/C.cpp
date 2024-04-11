#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, s; 
        cin >> a >> s;
        long long b = 0LL, mult = 1LL;
        bool work = true;
        while (s) {
            if (a % 10 <= s % 10) {
                b = mult * (s % 10 - a % 10) + b;
                mult *= 10;
                a /= 10, s /= 10;
            } else {
                if (s % 100 >= 10 && s % 100 < a % 10 + 10) {
                    b = mult * (s % 100 - a % 10) + b;
                    mult *= 10;
                    a /= 10, s /= 100;
                } else {
                    work = false;
                    break;
                }
            }
        }
        if (a || s) 
            work = false;
        if (work) cout << b << "\n";
        else cout << -1 << "\n";
    }
}