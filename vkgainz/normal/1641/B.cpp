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
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++f[a[i]];
    }
    for (auto &it : f) {
        if (it.second % 2) {
            cout << -1 << "\n";
            return;
        }
    }
    set<int> s;
    vector<pair<int, int>> put;
    vector<int> ans;
    vector<int> left = a;
    int curr_shift = 0;
    while (!left.empty()) {
        ++curr_shift;
        for (int i = 1; i < left.size(); i++) {
            ++curr_shift;
            if (left[i] == left[0]) {
                vector<int> nxt;
                for (int j = 1; j < i; j++) {
                    put.push_back({curr_shift, left[j]});
                    ++curr_shift;
                }
                for (int j = i - 1; j >= 1; j--) {
                    nxt.push_back(left[j]);
                }
                for (int j = i + 1; j < left.size(); j++) {
                    nxt.push_back(left[j]);
                }
                ans.push_back(i * 2);
                left = nxt;
                break;
            }
        }
    }
    cout << put.size() << "\n";
    for (auto &it : put) {
        cout << it.first << " " << it.second << "\n";
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}