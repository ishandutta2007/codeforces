#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
vector<int> l[256], r[256];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) l[s[i]].push_back(i);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) r[s[i]].push_back(i);
    vector<pair<int, int>> ans;
    for (int i = 'a'; i <= 'z'; ++i) {
        for (int j = 0; j < (int)min(r[i].size(), l[i].size()); ++j)
            ans.emplace_back(l[i][j], r[i][j]);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        int j = (int)min(r[i].size(), l[i].size());
        while (j < (int)l[i].size() && r['?'].size() > 0) {
            ans.emplace_back(l[i][j], r['?'].back());
            r['?'].pop_back();
            ++j;
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        int j = (int)min(r[i].size(), l[i].size());
        while (j < (int)r[i].size() && l['?'].size() > 0) {
            ans.emplace_back(l['?'].back(), r[i][j]);
            l['?'].pop_back();
            ++j;
        }
    }
    while (l['?'].size() && r['?'].size()) {
        ans.emplace_back(l['?'].back(), r['?'].back());
        l['?'].pop_back();
        r['?'].pop_back();
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}