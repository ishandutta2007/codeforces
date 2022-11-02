#include <bits/stdc++.h>

using namespace std;

int n, k;
set<pair<int, int>> e;
vector<int> v;

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e.insert(make_pair(x, y));
        e.insert(make_pair(y, x));
        v.push_back(x);
        v.push_back(y);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); i++) {
        vector<int> ans;
        for (int j = 0; j < v.size(); j++) {
            if (j == i) continue;
            if (e.find(make_pair(v[i], v[j])) != e.end()) continue;
            int c1 = 0, c2 = 0;
            for (int o = 0; o < v.size(); o++) {
                if (e.find(make_pair(v[i], v[o])) != e.end()) {
                    c2++;
                    if (e.find(make_pair(v[j], v[o])) != e.end()) c1++;
                }
            }
            if (c1 * 100 >= k * c2) ans.push_back(v[j]);
        }
        printf("%d: %d", v[i], (int)ans.size());
        for (int j : ans) printf(" %d", j);
        puts("");
    }
}