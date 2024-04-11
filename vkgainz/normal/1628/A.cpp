#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> f(n + 1), f2(n + 1);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ++f[a[i]];
            while (f[mx]) {
                ++mx;
            }
        }
        //[0....mx - 1] filled
        int currmx = 0, maxmx = mx;
        int lst = 0;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            ++f2[a[i]];
            while (f2[currmx]) {
                ++currmx;
            }
            --f[a[i]];
            if (f[a[i]] == 0 && a[i] < mx) {
                mx = a[i];
            }
            if (currmx == maxmx) {
                b.push_back(currmx);
                for (int j = lst; j <= i; j++) {
                    --f2[a[j]];
                }
                lst = i + 1;
                currmx = 0;
                maxmx = mx;
            }
        }
        cout << b.size() << "\n";
        for (int x : b)
            cout << x << " ";
        cout << "\n";
    }
}