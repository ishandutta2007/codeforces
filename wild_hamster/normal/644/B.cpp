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
ll k,i,j,n,m,s,d,x,y,last_time;
ll a[1005605], fac[1005000];
queue<ll> f;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> k;
	ll last_time = -INF;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d",&x, &y);
		while (!f.empty() && f.front() <= x)
		{
			f.pop();
		}
		if (f.empty())
		{
		 printf("%I64d ", x+y);
		 f.push(x+y);
		 continue;
		}
		if (f.size() == k+1)
		{
			printf("-1 ");
			continue;
		}
		printf("%I64d ", f.back()+y);
	 	f.push(f.back()+y);
	}
	return 0;
}