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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<long long> vpref(n + 1);
    for (int i = 1; i <= n; i++) {
        vpref[i] = vpref[i - 1] + v[i - 1];
    }
    sort(v.begin(), v.end());
    vector<long long> upref(n + 1);
    for (int i = 1; i <= n; i++) {
        upref[i] = upref[i - 1] + v[i - 1];
    }
    int m; cin >> m;
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
    
        if (t == 1) {
            cout << vpref[r] - vpref[l - 1] << "\n";        
        } else {
            cout << upref[r] - upref[l - 1] << "\n";
        }
    }
}