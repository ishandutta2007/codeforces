#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    vector<int> ck;
    for (auto it : cnt) ck.push_back(it.second);
    sort(ck.begin(), ck.end());
    int ans = 0;
    for (int i = 0; i < (int)ck.size(); ++i) {
        for (int k = 1; k <= ck[i]; ++k) {
            int j = i + 1, x = k * 2, cur = k;
            while (j < ck.size() && ck[j] >= x) ++j, cur += x, x *= 2;
            ans = max(ans, cur);
        }
    } 
    printf("%d\n", ans);
    return 0;
}