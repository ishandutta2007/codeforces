#include <bits/stdc++.h>

using namespace std;

int a[500005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    long long ans = 0;

    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> rem(2, 0);
    for(int i = 1; i <= n; i++) {
        ans += a[i] / 2;
        a[i] %= 2;
        if (a[i]) rem[i % 2]++;
    }

    cout << ans + min(rem[0], rem[1]);
}