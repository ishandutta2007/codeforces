#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF (1LL+(ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 200000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag;
ll a[N+500], p[15];
string s;
ll cnt(ll x, ll y)
{
	ll to = 0, ii = 1;
	for (int i = 0; i < y; i++)
	{
		a[x%7]++;
		to += (x%7)*ii;
		ii *= 7;
		if (a[x%7] > 1)
		   flag = 0;
		x /= 7;
	}
	return to;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	k = n-1;
	if (k == 0)
	   x = 1;
	else
	while (k)
	{
		x++;
		k/=7;
	}
	
	k = m-1;
	if (k == 0)
	   y = 1;
	else
	while (k)
	{
		y++;
		k/=7;
	}
	if (x+y > 7)
	{
		cout << 0 << endl;
		return 0;
	}
	p[0] = 1;
	for (i = 1; i <= 9; i++)
		p[i] = p[i-1]*7;
	ll ans = 0;
	for (i = 0; i < p[x]; i++)
		for (j = 0; j < p[y]; j++)
		{
			flag = 1;
			if (!flag)
			   continue;
			   
			for (k = 0; k < 7; k++)
				a[k] = 0;
			ll x1 = cnt(i, x);
			ll y1 = cnt(j, y);
			
			if (x1 < n && y1 < m && flag)
			{
			   ans++;
			   //cout << i << " " << j << " " << x1 << " " << y1 << endl;
			}
		}
	cout << ans << endl;
	return 0;
}