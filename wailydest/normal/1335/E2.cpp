#include <iostream>
#include <vector>
using namespace std;

const int amount = 200;

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<vector<int> > ind(amount);
    vector<vector<int> > pr(n, vector<int>(amount));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        --arr[i];
        ind[arr[i]].push_back(i);
        if (i != 0) pr[i] = pr[i - 1];
        ++pr[i][arr[i]];
    }
    int ans = 1;
    for (int i = 0; i < amount; ++i) {
        int cur;
        for (int b = 0, e = (int)ind[i].size() - 1; b < e; ++b, --e) {
            cur = 0;
            for (int el = 0; el < amount; ++el) cur = max(cur, pr[ind[i][e]][el] - pr[ind[i][b]][el] - (arr[ind[i][e]] == el));
            ans = max(ans, cur + (b + 1) * 2);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}