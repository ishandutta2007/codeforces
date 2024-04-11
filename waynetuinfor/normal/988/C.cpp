#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 2e5 + 5;
cc_hash_table<int, pair<int, int>> cc;

int main() {
    int k; scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int n; scanf("%d", &n);
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            int x; scanf("%d", &x);
            v.push_back(x);
        }
        int s = accumulate(v.begin(), v.end(), 0);
        for (int j = 0; j < n; ++j) {
            if (cc.find(s - v[j]) != cc.end()) {
                puts("YES");
                printf("%d %d\n", i + 1, j + 1);
                printf("%d %d\n", cc[s - v[j]].first + 1, cc[s - v[j]].second + 1);
                return 0;
            }
        }
        for (int j = 0; j < n; ++j) cc[s - v[j]] = make_pair(i, j);
    }   
    puts("NO");
    return 0;
}