#include <bits/stdc++.h>
using namespace std;

int a[105];
set<int> s;

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) s.insert(i);
    auto leader = s.begin();
    for (int i = 0; i < k; ++i) {
        auto it = leader;
        for (int j = 0; j < a[i] % s.size(); ++j) {
            it++;
            if (it == s.end()) it = s.begin();
        }
        leader = it;
        ++leader;
        if (leader == s.end()) leader = s.begin();
        cout << *it << ' ';
        s.erase(it);
    }
    return 0;
}