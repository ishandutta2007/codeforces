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
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            --p[i];
        }
        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans(n, -1);
        vector<bool> left(n, 1);
        int lst = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (left[j] && p[i] != j) {
                    ans[i] = j;
                    left[j] = false;
                    if (i == n - 2) {
                        lst = j;
                    }
                    break;
                }
            }
        }
        if (ans[n - 1] == -1) {
            ans[n - 1] = lst;
            for (int j = 0; j < n; j++) {
                if (left[j]) {
                    ans[n - 2] = j;
                    break;
                }
            }
        } else {
        }
        for (int i =0; i < n; i++) {
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    }
}