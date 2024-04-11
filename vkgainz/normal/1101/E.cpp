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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int mxX = 0, mxY = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '+') {
            int x, y; cin >> x >> y;
            if (x >= y)
                swap(x, y);
            mxX = max(mxX, x);
            mxY = max(mxY, y);
        } else {
            int h, w; cin >> h >> w;
            if (h >= w)
                swap(h, w);
            if (mxX > h || mxY > w) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
            }
        }
    }
}