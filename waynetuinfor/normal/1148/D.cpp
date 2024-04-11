#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] < b[i]) x.push_back(i);
        if (a[i] > b[i]) y.push_back(i);
    }

    sort(x.begin(), x.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    sort(y.begin(), y.end(), [&](int i, int j) {
        return b[i] < b[j];
    });

    vector<int> ans1, ans2;
    for (int i = 0, j = 0; i < (int)x.size(); ++i) {
        if (i == 0 || j > a[x[i]]) {
            ans1.push_back(x[i]);
            j = b[x[i]];
        }
    }
    for (int i = 0, j = 0; i < (int)y.size(); ++i) {
        if (i == 0 || j < a[y[i]]) {
            ans2.push_back(y[i]);
            j = b[y[i]];
        }
    }
    if ((int)ans1.size() < (int)ans2.size()) swap(ans1, ans2);
    printf("%d\n", (int)ans1.size());
    for (int i = 0; i < (int)ans1.size(); ++i)
        printf("%d ", ans1[i] + 1);
    puts("");
}