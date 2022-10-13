#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2 + 1) << "\n";
    } else {
        cout << 2 * (n / 2 + 2) * (n / 2 + 1) << "\n";
    }
}