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
ll n, k,j,i,m,q,ii,timer,x1,y,x,t;
ll min1, max1;
ll a[1005000];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	x = 0; y = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%I64d",&t);
		if (t == 2)
		{
			if (x%2 == 0)
			   x++, y--;
			else
				x--, y++;
		} else
		{
			scanf("%I64d",&t);
			x += t;
			y += t;
		}
	}
	x = x%n;
	if (x < 0)
	   x += n;
	x++;
	y = (y+1)%n;
	if (y < 0)
		  y += n;
	y++;
	for (i = 0; i < n/2; i++)
		a[(x+i*2-1)%n+1] = i*2+1;
	for (i = 0; i < n/2; i++)
		a[(y+i*2-1)%n+1] = i*2+2;
	for (i = 1; i <= n; i++)
		printf("%I64d ",a[i]);
	return 0;
}