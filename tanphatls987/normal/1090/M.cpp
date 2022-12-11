#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int en = 1; en <= n; ) {
        int st = en;
        while (en < n && a[en + 1] != a[en]) en++;
        ans = max(ans, en - st + 1);
        en++;
    }
    cout << ans;
}