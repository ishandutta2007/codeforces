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
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            ++f[a[i]];
        }
        if (*min_element(f.begin(), f.end()) == 0) {
            cout << "YES" << "\n";
        } else {
            vector<bool> vis(n);
            bool work = true;
            int numEven = 0;
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    continue;
                }
                vis[i] = true;
                int curr = i;
                int len = 1;
                while (!vis[a[curr]]) {
                    curr = a[curr];
                    vis[curr] = true;
                    ++len;
                }
                if (len % 2 == 0) {
                    ++numEven;
                }
            }
            work = numEven % 2 == 0;
            if (!work) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
            }
        }
    }
}