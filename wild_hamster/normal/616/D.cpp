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
ll a[500500]; 
pair<ll,ll> t[4000050];
void update (ll v, ll tl, ll tr, ll pos) {
	if (tl == tr)
	{
		t[v].first++;
		if (t[v].first == 1)
			t[v].second = 1;
	}
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos);
		else
			update (v*2+1, tm+1, tr, pos);
		t[v].second = t[v*2].second + t[v*2+1].second;
	}
}

void update1 (ll v, ll tl, ll tr, ll pos) {
	if (tl == tr)
	{
		t[v].first--;
		if (t[v].first == 0)
			t[v].second = 0;
	}
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update1 (v*2, tl, tm, pos);
		else
			update1 (v*2+1, tm+1, tr, pos);
		t[v].second = t[v*2].second + t[v*2+1].second;
	}
}


ll sum (ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v].second;
	ll tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
    	scanf("%I64d", &a[i]);
    ll N = 1000001;
    for (i = 0; i < n; i++)
    {
    	update(1,0,N,a[i]);
    	if (sum(1,0,N,0,N) > k)
	    	break;
    }
    if (i == n)
    {
    	cout << 1 << " " << n << endl;
    	return 0;
    }
    ll ans = i, l = 1, r = i;
    ll l1 = 0;
    for (j = i; j < n; j++)
    {
    	//cout << j << endl;
    	while (sum(1,0,N,0,N) > k)
    	{
    		update1(1,0,N,a[l1]);
    		l1++;
    	}
    	update(1,0,N,a[j+1]);
    	if (j - l1 + 1 > ans)
    	{
    		ans = j - l1 + 1;
    		l = l1+1; r = j+1;
    	}
    }
    cout << l << " " << r << endl;
    return 0;
}