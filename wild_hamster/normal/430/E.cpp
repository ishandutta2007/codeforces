#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sums[30000],dp[25][3000][25],can[3000],n,i,j,k,x,y,a[300];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
            cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    for (i = 0; i < n; i++)
        if (a[i] == 1)
        {
            k = i;
            break;
        }
    if (k == 0)
    {
        if (n == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (k > 11)
    {
    cout << "NO" << endl;
    return 0;
    }
    for (i = 0; i < (1<<k); i++)
    {
        ll cnt = 0;
        for (j = 0; j < k; j++)
            if (i&(1<<j)) sums[i] += a[j],cnt++;
        can[i] = cnt;
    }
    dp[0][1][0] = 1;
    for (i = 0; i < k; i++)
        for (j = 0; j < (1<<k); j++)
            if (j&((1<<(i+1))-1) == (1<<(i+1))-1)
                for (x = 0; x <= n-k; x++)
                {
                    ll tmp = (1<<k) - 1 - j;
                    for (y = tmp;;y=((y-1)&tmp))
                    {
                    if (a[i]-sums[y]-1>=0 && can[y]+a[i]-sums[y]-1!=1)
                    {
                        if (dp[i][j][x] == 1 && x+a[i]-sums[y]-1<=n-k && a[i]-sums[y]-1>=0)
                        {
                            //cout << i << " " << j << " " << y << " " << x+a[i]-sums[y]-1 << endl;
                            dp[i+1][j|y][x+a[i]-sums[y]-1] = 1;
                        }
                    }                   
                        if (y == 0) break;
                    }
                }
    //cout << (n-k) << endl;
    //for (i = 0; i <= n-k; i++)
    //  cout << dp[k][(1<<k)-1][i] << " ";
    if (dp[k][(1<<k)-1][n-k])
        cout << "YES" << endl;
        else cout <<"NO" << endl;
    return 0;
}