#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<long long> a;
        long long st = 0LL;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
            st += x;
        }
        int cut = 0;
        multiset<long long> in;
        in.insert(st);
        bool work = true;
        while (a.size() > 0) {
            if (cut > n - 1 || in.size() == 0) {
                work = false;
                break;
            }
            multiset<long long> nxt;
            for (auto &it : in) {
                if (a.count(it)) {
                    a.erase(a.lower_bound(it));
                    continue;
                } else {
                    nxt.insert(it);
                }
            }
            in.clear();
            for (auto &it : nxt) {
                ++cut;
                in.insert(it / 2);
                in.insert((it + 1) / 2);
            }
        }
        if (work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}