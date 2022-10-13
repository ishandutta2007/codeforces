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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    double lo = 0.0, hi = 1e9 + 5;
    for (int j = 0; j < 80; j++) {
        double mid = (lo + hi) / 2;
        double tmp = mid;
        bool work = true;
        for (int i = 0; i < n; i++) {
            double tot = mid + m;
            double need = tot / a[i];
            if (need > mid) {
                work = false;
                break;
            }
            mid -= need;
            tot = mid + m;
            need = tot / b[(i + 1) % n];
            if (need > mid) {
                work = false;
                break;
            }
            mid -= need;
        }
        if (!work) {
            lo = tmp;
        } else {
            hi = tmp;
        }
    }
    cout << setprecision(24);
    if (lo > 1e9 + 3) 
        cout << -1 << "\n";
    else 
        cout << lo << "\n";
}