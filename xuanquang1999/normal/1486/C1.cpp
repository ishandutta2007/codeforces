#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int ask(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);

    int res;
    scanf("%d", &res);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    int max2 = ask(1, n);

    int l, r;
    // maximum is in [1, max2-1]
    if (max2 == n || (max2 > 1 && ask(1, max2) == max2)) {
        l = 1, r = max2-1;
        while (r-l+1 > 2) {
            int mid = (l + r) / 2;
            // maximum is in [mid+1, max2]
            if (ask(mid+1, max2) == max2) {
                l = mid + 1;
            } else
                r = mid;
        }
    }
    // maximum is in [max2+1, n]
    else {
        l = max2+1, r = n;
        while (r-l+1 > 2) {
            int mid = (l + r) / 2;
            // maximum is in [max2, mid]
            if (ask(max2, mid) == max2) {
                r = mid;
            } else
                l = mid + 1;
        }
    }

    int ans;
    if (l < r)
        ans = l + r - ask(l, r);
    else
        ans = l;

    printf("! %d\n", ans);
    fflush(stdout);

    return 0;
}