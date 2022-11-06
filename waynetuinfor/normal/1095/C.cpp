#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    if (k > n) {
        puts("NO");
        return 0;
    }
    vector<int> ans;
    for (int d = 30; d >= 0; --d) {
        while (k && n >= (1 << d) && (k - 1) <= (n - (1 << d))) {
            --k;
            n -= (1 << d);
            ans.push_back(1 << d);
        }
    }
    if (n != 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}