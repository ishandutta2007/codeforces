#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a = (1 << 29);
        long long sub = 0;
        for (int i = 1; i <= 30; i++) {
            long long b = a - sub + (1LL << i);
            cout << "? " << a - sub << " " << b << "\n";
            long long gcd; cin >> gcd;
            if (gcd != (1LL << i)) { // (x + a) is 0 mod 2^i
                sub += gcd;
            }
            if (i == 30) {
                if (sub >= (1 << 29)) {
                    cout << "! " << sub - (1 << 29) << "\n";
                } else {
                    cout << "! " << sub + (1 << 29) << "\n";
                }
            }
        }
    }
}