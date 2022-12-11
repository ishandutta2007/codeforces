#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int N = 1e3 + 10;

int n, a[N][N], ans[N];

int mySqrt(ll x) {
    ll y = int(sqrt(x));
    while (y * y < x) y++;
    return y;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    ans[1] = mySqrt(1LL * a[1][2] * a[1][3] / a[2][3]);
    for(int i = 2; i <= n; i++) 
        ans[i] = a[1][i] / ans[1];
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}