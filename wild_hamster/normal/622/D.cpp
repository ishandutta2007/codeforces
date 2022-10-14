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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
ll a[1000500], b[1000500];
vector <ll> num[1000500];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	if (n == 1)
	{
		cout << "1 1" << endl;
		return 0;
	}
	ll x = n%2 + 1;
	ll sz = 0;
	ll cur = n%2+1;
	for (i = 0; i < n/2; i++)
	{
		a[sz++] = cur;
		cur += 2;
	}
	cur -= 2;
	for (i = 0; i < n/2; i++)
	{
		a[sz++] = cur;
		cur -= 2;
	}
	a[sz++] = n;
	
	cur = (n+1)%2 + 1;
	for (i = 0; i < n-1-n/2; i++)
	{
		a[sz++] = cur;
		cur += 2;
	}
	cur -= 2;
	a[sz++] = n;
	for (i = 0; i < n-1-n/2; i++)
	{
		a[sz++] = cur;
		cur -= 2;
	}
	for (i = 0; i < sz; i++)
		printf("%d ", a[i]);
	cout << endl;
	return 0;
}