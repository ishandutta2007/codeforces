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
ll dp[205][205][205];
string s;
int main()
{
	cin >> n;
	cin >> s;
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'B')
			x++;
		else if (s[i] == 'G')
			y++;
	}
	dp[0][x][y] = 1;
	for (i = 0; i < n-1; i++)
		for (x = 0; x <= n; x++)
			for (y = 0; y <= n; y++)
				if (dp[i][x][y])
				{
					//cout << x << " " << y << endl;
					if (x > 0 && y > 0)
					{
						dp[i+1][x-1][y-1] = 1;
					}
					if (x > 0 && n-i-x-y > 0)
					{
						dp[i+1][x-1][y+1] = 1;
					}
					if (y > 0 && n-i-x-y > 0)
					{
						dp[i+1][x+1][y-1] = 1;
					}
					if (x > 1)
					{
						dp[i+1][x-1][y] = 1;
					}
					if (y > 1)
						dp[i+1][x][y-1] = 1;
					if (n-i-x-y > 1)
						dp[i+1][x][y] = 1;
				}
	if (dp[n-1][1][0] == 1)
		cout << "B";	
	if (dp[n-1][0][1] == 1)
		cout << "G";
	if (dp[n-1][0][0] == 1)
		cout << "R";
	cout << endl;
	return 0;
}