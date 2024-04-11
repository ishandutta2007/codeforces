#include <bits/stdc++.h>
#define maxN 100005

using namespace std;

int n, a[maxN], s[2][2], cnt;
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a, a+n);

    for (int i = n-2; i >= 0; --i)
        if (a[i+1] - a[i] <= 1) {
            s[cnt][0] = a[i];
            s[cnt][1] = a[i+1];
            ++cnt; --i;
            if (cnt == 2) {
                long long x, y;
                x = min(s[0][0], s[0][1]);
                y = min(s[1][0], s[1][1]);
                ans = ans + x*y;
                cnt = 0;
            }
        }

    cout << ans;

    return 0;
}