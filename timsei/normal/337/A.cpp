#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int ans = 0 , n , a[N] , m;

int main(void) {
    scanf("%d%d" , &n , &m);
    for(int i = 1;i <= m;++ i) cin >> a[i];
    sort(a + 1 , a + m + 1);
    ans = 233 * 666 * 666;
    ans = 2e9;
    for(int i = 1;i <= m - n + 1;++ i) {
        ans = min(ans , a[i + n - 1] - a[i]);
    }
    cout << ans;
}