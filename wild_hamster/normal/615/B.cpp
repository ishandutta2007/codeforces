#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], dp[4000500], back[4000050], t[4000050];
string s;
set <ll> f;
vector <ll> g[300500];
set <ll>::iterator itr;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        f.insert(a[i]);
        f.insert(b[i]);
    }
    for (i = 0; i < 300000; i++)
        dp[i] = 1;
    i = 0;
    
    long long ans = 0;
    for (itr = f.begin(); itr != f.end(); itr++)
    {
        i++;
        x = *itr;
        for (j = 0; j < g[x].size(); j++)
            if (g[x][j] > x)
                dp[g[x][j]] = max(dp[g[x][j]], dp[x] + 1);
        //cout << i << " " << *itr << " " << dp[*itr] << endl;
        ans = max(ans, (long long)g[x].size()*dp[x]);
    }
    cout << ans << endl;
    return 0;
}