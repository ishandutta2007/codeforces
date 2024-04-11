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
//#define temo

using namespace std;
const ll N = 100005;

ll n, m;
ll a[15][N], b[15][N];
ll c[15];
ll ans;
int main()
{
    cin>>n>>m;
    for (ll i = 1; i <= m; i++)
        for (ll j = 1; j <= n; j++){
            //cin>>a[i][j];
            scanf ("%lld", &a[i][j]);
            b[i][a[i][j]] = j;
        }
    for (ll i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            c[j] = b[j][a[1][i]];
        bool ok = 1;
        while (c[1] < n){
            for (int j = 1; j < m; j++)
                if (a[j][c[j] + 1] != a[j + 1][c[j + 1] + 1])
                    ok = 0;
            if (ok == 0){
                break;
            }
            for (ll j = 1; j <= m; j++)
                c[j]++;
        }
        ans += (c[1] - i + 1) * (c[1] - i + 2) / 2;
        i = c[1];
    }
    cout<<ans<<endl;
    return 0;
}