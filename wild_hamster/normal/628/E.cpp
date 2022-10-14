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
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll a[6005][6005], t[24005];
ll pre_left[6005][6005], pre_right[6005][6005];
set <pii> f;
set <pii>::iterator itr;
char s[3005];
void update (ll v, ll tl, ll tr, ll pos, ll new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

ll sum (ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		scanf("%s",s);
		for (j = 0; j < m; j++)
			if (s[j] == 'z')
			   a[i][j] = 1;
	}
	for (i = 0; i < n; i++)
	{
		ll tmp = 0;
		for (j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			   tmp++;
			else
				tmp = 0;
			pre_left[i][j] = tmp;
		}
		
		tmp = 0;
		for (j = m-1; j >= 0; j--)
		{
			if (a[i][j] == 1)
			   tmp++;
			else
				tmp = 0;
			pre_right[i][j] = tmp;
		}
	}
	long long ans = 0;
	for (i = 0; i < 6002; i++)
	{
		while (f.size() != 0)
				{
					itr = f.begin();
					update(1,0,6001,(*itr).Y,0);
					f.erase(itr);
				}
				k = 0;
		k = 0;
		for (j = 0; j < m; j++)
		{
			if (i - j < 0)
			   break;
			if (a[i-j][j] == 0)
			{
				while (f.size() != 0)
				{
					itr = f.begin();
					update(1,0,6001,(*itr).Y,0);
					f.erase(itr);
				}
				k = 0;
			}
			if (a[i-j][j] == 1)
			{
				k++;
				f.insert(mp(j+pre_right[i-j][j], j));
				update(1,0,6001,j,1);
				itr = f.begin();
				while ((*itr).X <= j)
				{
					update(1,0,6001,(*itr).Y,0);

					f.erase(itr);
					if (f.empty())
					   break;
					itr = f.begin();
				}
				ans += sum(1,0,6001,j-pre_left[i-j][j]+1,j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}