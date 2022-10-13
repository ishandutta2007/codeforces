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
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int lst = n - 1;
        vector<int> p(n);
        for (int i = n - 1; i >= 1; i--) {
            if (s[i - 1] < s[i]) {
                p[i] = lst;
                lst = i - 1;
            } else {
                p[i] = i - 1;
            }
        }
        p[0] = lst;
        bool work = true;
        for (int i = 0; i < n; i++) {
            if (p[i] == i) {
                work = false;
            }
        }
        if (work) {
            for (int i = 0; i < n; i++) {
                cout << p[i] + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}