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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        set<int> in;
        bool work = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            in.insert(a[i]);
            if (in.count(a[i] + k) || in.count(a[i] - k)) {
                work = true;
            }
        }
        if (work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}