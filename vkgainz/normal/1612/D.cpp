#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <chrono>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b, x; cin >> a >> b >> x;
        if (a > b)
            swap(a, b);
        if (x > b) {
            cout << "NO" << "\n";
        } else {
            while (x < a) {
                b = b % a;
                if (a > b)
                    swap(a, b);
            }
            if (x == a || (a > 0 && b % a == x % a)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";   
            }
        }
    }
}