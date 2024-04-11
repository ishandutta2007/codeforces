#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> f, l;
    map<int, int> occ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (f.find(a[i]) == f.end()) {
            f[a[i]] = i;
        }
        l[a[i]] = i;
        ++occ[a[i]];
    }
    pair<int, int> ans = {0, -1};
    int mst = 0;
    for (auto &it : f) {
        int val = it.first;
        int len = l[val] - f[val] + 1;
        int num = occ[val];
        if (num > mst) {
            mst = num;
            ans = {val, len};
        } else if (num == mst) {
            if (len < ans.second) {
                ans = {val, len};
            }
        }
    }
    cout << f[ans.first] + 1 << " " << l[ans.first] + 1 << "\n";
}