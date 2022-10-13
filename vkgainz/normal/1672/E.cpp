#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
int query(int w) {
    cout << "? " << w << "\n";
    cout.flush();
    int h_w; cin >> h_w;
    return h_w;
}

int main() {
    int n; cin >> n;
    int lo = 1, hi = 1e8;
    for (int j = 0; j < 30; j++) {
        int mid = (lo + hi) / 2;
        int h_w = query(mid);
        if (h_w != 1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    int T = lo + 1;
    int area = 1000000000;
    for (int i = 1; i <= n; i++) {
        int nxt = (T - 1) / i;
        int h_i = query(nxt);
        if (h_i == 0 || h_i > i) continue;
        area = min(area, nxt * i);
    }
    cout << "! " << area << "\n";
}