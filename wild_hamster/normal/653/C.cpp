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
typedef long long ll;
typedef long double ld;
using namespace std;
ll k,i,j,n,m,d,x,y,w,dw,l;
ll a[400500], b[400500];
vector<ll> f;
bool good_pos(ll x)
{
	if (x%2)
	{
		if ((a[x] > a[x-1] || x == 0) && (a[x] > a[x+1] || x == n-1))
		   return true;
		return false;
	}
	if ((a[x] < a[x-1] || x == 0) && (a[x] < a[x+1] || x == n-1))
	   return true;
	return false;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n-1; i++)
		if ((i%2 == 0 && a[i] >= a[i+1])||(i%2 == 1 && a[i] <= a[i+1]))
		   f.push_back(i);
	if (f.size() > 4)
	{
		cout << 0 << endl;
		return 0;
	}
	if (f.size() == 4)
	{
		if (f[0] + 1 != f[1] || f[2] + 1 != f[3])
		{
			cout << 0 << endl;
			return 0;
		}
		swap(a[f[1]], a[f[3]]);
		if (good_pos(f[1]) && good_pos(f[3]))
		   cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	if (f.size() == 3)
	{
		if (f[0] + 1 == f[1])
		{
			ll ans = 0;
			swap(a[f[1]], a[f[2]]);
			if (good_pos(f[1]) && good_pos(f[2]))
			   ans++;
			swap(a[f[1]], a[f[2]]);
			   
			swap(a[f[1]], a[f[2]+1]);
			if (good_pos(f[1]) && good_pos(f[2]+1))
			   ans++;
			   
			cout << ans << endl;
			return 0;
		}
		if (f[1] + 1 == f[2])
		{
			ll ans = 0;
			swap(a[f[2]], a[f[0]]);
			if (good_pos(f[0]) && good_pos(f[2]))
			   ans++;
			swap(a[f[2]], a[f[0]]);

			swap(a[f[2]], a[f[0]+1]);
			if (good_pos(f[2]) && good_pos(f[0]+1))
			   ans++;

			cout << ans << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	if (f.size() == 2)
	{
		if (f[0] + 1 == f[1])
		{
			ll ans = 0;
			for (i = 0; i < n; i++)
				if (i != f[1])
				{
					swap(a[i], a[f[1]]);
					if (good_pos(i) && good_pos(f[1]))
					   ans++;
					swap(a[i], a[f[1]]);
				}
			cout << ans << endl;
			return 0;
		}
		ll ans = 0;
		for (i = f[0]; i <= f[0] + 1; i++)
			for (j = f[1]; j <= f[1] + 1; j++)
			{
				swap(a[i], a[j]);
				if (good_pos(i) && good_pos(j))
				   ans++;
				swap(a[i], a[j]);
			}
		cout << ans << endl;
		return 0;
	}
	//cout << "KOKO" << endl;
	ll ans = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
		if (i != f[0]+j)
		{
			if (i == f[0] && j == 1)
			   continue;
			swap(a[i], a[f[0]+j]);
			if (good_pos(i) && good_pos(f[0]+j))
			   ans++;
			swap(a[i], a[f[0]+j]);
		}
	cout << ans << endl;
	return 0;
}