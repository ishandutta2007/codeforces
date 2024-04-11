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
        long long n; cin >> n;
        n = n << 1;
        long long a = 1LL, b = n;
        while (b % 2 == 0) {
            a *= 2;
            b /= 2;
        }
        if (a > 1 && a <= n / (a + 1)) {
            cout << a << "\n";
        } else if (b > 1 && b <= n / (b + 1)) {
            cout << b << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}