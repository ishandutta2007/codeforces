#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int lo = 0, hi = 100000000;
    for(int j = 0; j < 30; j++) {
        int mid = (lo + hi) / 2;
        int same = mid / 6;
        int diff1 = (mid / 6) * 2;
        if (mid % 6 >= 2) ++diff1;
        if (mid % 6 >= 4) ++diff1;
        int diff2 = (mid / 6);
        if(mid % 6 >= 3) ++diff2;
        int a = n - diff1, b = m - diff2;
        a = max(a, 0), b = max(b, 0);
        if (a + b <= same) {
            hi = mid;
        }
        else lo = mid + 1;
    }
    cout << lo;
}