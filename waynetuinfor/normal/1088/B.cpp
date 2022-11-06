#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if (x > 0) v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long sub = 0;
    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (j < (int)v.size() && v[j] <= sub) ++j;
        if (j == (int)v.size()) printf("%d\n", 0);
        else printf("%d\n", v[j] - sub), sub += v[j] - sub;
    }
    return 0;
}