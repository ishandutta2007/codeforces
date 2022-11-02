#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &e[i]);
    }
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    int ans = 0;
    for (int i = 0; i < n; i += k) {
        ans += 2 * (e[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}