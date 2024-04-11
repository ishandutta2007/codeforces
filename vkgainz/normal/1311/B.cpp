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
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> p(m);
        for (int i = 0; i < m ;i++) {
            cin >> p[i];
            --p[i];
        }
        sort(p.begin(), p.end());
        int j = 0;
        vector<pair<int, int>> tst;
        for (int i = 0; i < m; i++) {
            while (j < m && (j == i || p[j] - p[j - 1] == 1)) {
                ++j;
            }
            --j;
            //[p[i]...p[j] + 1]
            vector<int> tmp;
            for (int k = p[i]; k <= min(p[j] + 1, n - 1); k++) {
                tmp.push_back(a[k]);
            }
            sort(tmp.begin(), tmp.end());
            for (int k = p[i]; k <= min(p[j] + 1, n - 1); k++) {
                a[k] = tmp[k - p[i]];
            }
            i = j;
            ++j;
        }
        bool work = true;
        for (int i = 1; i < n; i++) 
            work &= a[i] >= a[i - 1];
        if (work)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}