#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const ll N = 2e5 + 5, MOD = 1e9 + 7;

ll dp[N][3];
ll n, l, r;
ll a[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> r;
    while (l % 3 != 0){
        a[l % 3]++;
        l++;
    }
    while (r % 3 != 0){
        a[r % 3]++;
        r--;
    }
    a[0]++;
    for (int i = 0; i < 3; i++)
        a[i] += (r - l) / 3;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            for (int l = 0; l < 3; l++)
                dp[i][(j + l) % 3] = (dp[i][(j + l) % 3] + dp[i - 1][j] * a[l]) % MOD;
    cout << dp[n][0] << endl;
    return 0;
}