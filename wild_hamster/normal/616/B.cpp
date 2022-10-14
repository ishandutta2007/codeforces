#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1005][1005];
int main()
{
    cin >> n >> m;
    ll ans = -1;
    for (i = 0; i < n; i++)
    {
    	y = MOD;
    	for (j = 0; j < m; j++)
    	{
    		cin >> x;
    		y = min(y,x);
    	}
    	ans = max(ans,y);
    }
    cout << ans << endl;
    return 0;
}