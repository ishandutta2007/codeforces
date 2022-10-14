#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(2 * n);
        vector<int> cnt(2);
        for (int i = 0; i < 2 * n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i] % 2]++;
        }
        if (cnt[0] == cnt[1]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}