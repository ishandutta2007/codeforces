#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[500500]; 
pair<ll,ll> t[4000050];

int main()
{
    cin >> n >> k;
    ll ans = 0;
    if (k < 4000000)
    {
    	for (i = 1; i <= k; i++)
    		ans += n%i;
    	cout << ans % MOD << endl;
    	return 0;
    }
    x = (ll)sqrt(n);
    for (i = 1; i <= n/x; i++)
    	ans += n%i;
    ans %= MOD;
    for (i = x; i >= 2; i--)
    {
    	ll l = n/i+1;
    	ll r = n/(i-1);
    	ll step = i-1;
    	if (k >= l && k <= r)
    	{
    		ll dif = k-l+1;    		
    		ans += ((dif%MOD)*((n%k)%MOD)) % MOD;
    		if (ans >= MOD)
    			ans -= MOD;
    		if (dif % 2 == 0)
    			ans += ((((step%MOD)*((dif/2)%MOD))%MOD) * ((dif-1)%MOD))%MOD;
    		else
    			ans += ((((step%MOD)*(((dif-1)/2)%MOD))%MOD) * (dif%MOD))%MOD;
    		if (ans >= MOD)
    			ans -= MOD;
    		break;
    	}
    	{
    		ll dif = r-l+1;    		
    		ans += ((dif%MOD)*((n%r)%MOD)) % MOD;
    		if (ans >= MOD)
    			ans -= MOD;
    		if (dif % 2 == 0)
    			ans += ((((step%MOD)*((dif/2)%MOD))%MOD) * ((dif-1)%MOD))%MOD;
    		else
    			ans += ((((step%MOD)*(((dif-1)/2)%MOD))%MOD) * (dif%MOD))%MOD;
    		if (ans >= MOD)
    			ans -= MOD;
    	}
    }
    if (k > n)
    {
    	ans += ((k-n)%MOD) * (n%MOD);
    	ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}