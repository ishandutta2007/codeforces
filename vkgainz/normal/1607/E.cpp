#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        int dx = 0, dy = 0;
        pair<int, int> x = {0, 0}, y = {0, 0};
        pair<int, int> st = {1, 1};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') ++dx;
            else if (s[i] == 'L') --dx;
            else if (s[i] == 'U') --dy;
            else ++dy;
            x = {min(x.first, dx), max(x.second, dx)};
            y = {min(y.first, dy), max(y.second, dy)};
            if (x.second - x.first + 1 <= m
                    && y.second - y.first + 1 <= n) {
                st = {-y.first + 1, -x.first + 1};
            }
        }
        cout << st.first << " " << st.second << "\n";
    }
}