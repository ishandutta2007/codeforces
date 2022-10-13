#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s; cin >> s;
        vector<int> r, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                b.push_back(a[i]);
            } else {
                r.push_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        sort(r.begin(), r.end());
        int curr = 1;
        bool work = true;
        for (int x : b) {
            if (x < curr) {
                work = false;
            }
            ++curr;
        }
        for (int x : r) {
            if (x > curr) {
                work = false;
            }
            ++curr;
        }
        if (work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}