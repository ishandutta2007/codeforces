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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD2 1000000007
#define MOD 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 100500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,cur_x,cur_y;
ll a[200500], b[200500];
vector<pii> g[100500];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if (b[i] != 1)
		   x = 1;
	}
	if (x == 0)
	{
		cout << "Infinity" << endl;
		return 0;
	}
	ll l = -300000000, r = 300000000;
	while (l < r)
	{
		ll mid = (l+r+1)/2;
		ll flag = 0;
		ll start = mid;
		for (i = 0; i < n; i++)
		{
			if (start >= 1900 && b[i] == 2)
			{
			   flag = 1;
			   break;
			   }
			start += a[i];
		}
		if (flag)
		   r = mid-1;
		else
			l = mid;
	}
	ll start = l;
	for (i = 0; i < n; i++)
	{
		if (start >= 1900 && b[i] == 2 || start < 1900 && b[i] == 1)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		start += a[i];
	}
	cout << start << endl;
    return 0;
}