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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x; cin >> x;
        for (int i = 0; i < n; i++) {
            a[i] -= x;
        }
        long long mn = 0LL;
        int ans = 0;
        int run = 0;
        for (int i = 0; i < n; i++) {
            //try to choose a[i]??
            if (run == 0) {
                mn = a[i];
                ++ans;
                ++run;
            } else {
                if (mn + a[i] < 0) {
                    //bad!
                    run = 0;
                    mn = 0LL;
                } else {
                    //good??
                    ++ans;
                    ++run;
                    mn = min((long long) a[i], mn + a[i]);
                }
            }
        }
        cout << ans << "\n";
    }
}