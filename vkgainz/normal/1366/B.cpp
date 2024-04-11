#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <array>
 
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x, m; cin >> n >> x >> m;
        int l = x, r = x;
        for (int i = 0; i < m; i++) {
            int li, ri; cin >> li >> ri;
            if (ri < l || li > r) continue;
            l = min(l, li);
            r = max(r, ri);
        }
        cout << r - l + 1 << "\n";
    }
}