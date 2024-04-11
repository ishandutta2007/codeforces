#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord;
ll a[1000500], b[1000500], pb[1000500];
ll destr[100500], dp[1000050], prev[1000500];
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        a[x] = y;
        b[x] = 1;
    }
    for (i = 0; i <= 1000001; i++)
        pb[i+1] = pb[i] + b[i];
    dp[1000001] = 0;
    for (i = 0; i <= 1000000; i++)
        if (b[i] == 1)
            prev[i] = i;
        else
            prev[i] = prev[i-1];
    for (i = 1000000; i >= 0; i--)
        dp[i] = 100500;
    x = 0;
    for (i = 1000000; i >= 0; i--){
        if (b[i] != 0)
            dp[i] = x++;            
    }
    dp[1000004] = 100500;
    for (i = 1000000; i >= 0; i--) {
        if (dp[i] != 100500)
        {
            coord = i - a[i] - 1;
            if (coord < 0) {
                dp[1000004] = min(dp[1000004], dp[i] + pb[i]);
            } else {
                dp[prev[coord]] = min(dp[prev[coord]], dp[i] + pb[i] - pb[coord+1]);
            }
        }
    }
    /*for (i = 0; i < 10; i++)
        cout << dp[i] << " ";
    cout << endl;*/
    cout << dp[1000004] << endl;
    return 0;
}