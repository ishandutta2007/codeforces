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
ll dp[205][405][405];
pii moves[500];
string s;
int main()
{
	moves['R'] = mp(1, 0);
	moves['L'] = mp(-1, 0);
	moves['U'] = mp(0, 1);
	moves['D'] = mp(0, -1);
	cin >> n;
	cin >> s;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			ll x = 0, y = 0;
			for (k = i; k <= j; k++)
				x += moves[s[k]].X, y += moves[s[k]].Y;
			if (x == 0 && y == 0)
				l++;
		}
	cout << l << endl;		
	return 0;
}