#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x = 1, y = 1, z = 1;
        while ((x + 1) * (x + 1) <= n) {
            ++x;
        }
        while ((y + 1) * (y + 1) * (y + 1) <= n) {
            ++y;
        }
        while (pow(z + 1, 6) <= n) {
            ++z;
        }
        cout << x + y - z << "\n";
    }
}