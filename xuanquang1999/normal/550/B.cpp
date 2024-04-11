#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, ans;
vector<int> a, res;

void getSubset(int i) {
    if (i == n) {
        if (res.size() >= 2) {
            int sum = accumulate(res.begin(), res.end(), 0);
            int maxA = *max_element(res.begin(), res.end());
            int minA = *min_element(res.begin(), res.end());
            if (l <= sum && sum <= r && maxA-minA >= x)
                ++ans;
        }
        return;
    }
    for(int j = 0; j < 2; ++j) {
        if (j == 1)
            res.push_back(a[i]);
        getSubset(i+1);
        if (j == 1)
            res.pop_back();
    }
}

int main() {
    scanf("%d%d%d%d", &n, &l, &r, &x);

    a.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    getSubset(0);

    printf("%d\n", ans);

    return 0;
}