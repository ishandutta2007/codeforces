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
#define INF (1LL+(ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n, k, q, a[228228], another[228228], pa[228228],b[228228], b1,c,x, y,d,h;
vector<ll> ost[10];
multiset<ll> f;
multiset<ll>::iterator itr;
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> k >> b1 >> c;
	for (i = 0;i < n; i++)
	{
		scanf("%I64d",&a[i]);
		a[i] += 1000000000;
	}

	sort(a, a+n);
	if (5*c < b1)
	{
		ll ans = INF;
		for (i = 0; i < n; i++)
			pa[i+1] = pa[i] + a[i];
		for (i = k-1; i < n; i++)
			ans = min(ans, c*(k*a[i] - (pa[i+1]-pa[i-k+1])));
		cout << ans << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
			ost[(a[i]+j)%5].push_back(a[i]+j);
	}
	ll ans = INF;
	for (i = 0; i < 5; i++)
	{
		f.clear();
		for (j = 0; j < n; j++)
		{
			ll osta = (i - a[j]%5 + 5)%5;
			b[j] = -osta*c + ((a[j] + osta - i)/5)*b1;
		}
		ll pnt = 0;
		ll sum = 0;
		for (j = 0; j < ost[i].size(); j++)
		{
			ll v = ost[i][j];
			while (a[pnt] <= v && pnt < n)
			{
				if (f.size() < k)
				{
					f.insert(b[pnt]);
					sum += b[pnt];
				} else
				{
					itr = f.begin();
					if ((*itr) < b[pnt])
					{
						sum -= *itr;
						f.erase(itr);
						sum += b[pnt];
						f.insert(b[pnt]);
					}
				}
				pnt++;
			}
			if (f.size() == k)
				ans = min(ans, k*(b1*(v-i)/5) - sum);
		}
	}
	cout << ans << endl;
	return 0;
}