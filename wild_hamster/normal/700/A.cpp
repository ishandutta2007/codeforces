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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,sz, q;
ll a[3005], b[3005];
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ld le,v1,v2;
	cin >> n >> le >> v1 >> v2 >> k;
	ld dist = 0;
	ld ans = 0;
	ld l = 0, r = 1e+9;
	while (r-l > 1e-10)
	{
		ld mid = (l+r)/2;
		ld can = (le-mid*v1)/(v2-v1);
		ld dist = 0;
		ll flag = 1;
		for (i = 0; i < (n-1)/k+1; i++)
		{
			if (dist + can*v2 > le)
			{
			   flag = 0;
			   break;
			}
			dist += can*v1;
			if (i + 1 != (n-1)/k+1)
			   dist += (v2-v1)/(v2+v1)*can*v1;
		}
		if (flag)
		   r = mid;
		else
			l = mid;
	}
	printf("%.10f\n",(double)l);
	return 0;
}