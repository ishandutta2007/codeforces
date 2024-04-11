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
ll k,i,j,n,m,x,y,dw,l,cur, w[200500], used[200500];
ll a[105][105][105];
char s[105];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			{
				scanf("%s",s);
				for (l = 0; l < k; l++)
					a[i+1][j+1][l+1] = s[l]-'0';
			}
	ll ans = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			for (l = 1; l <= k; l++)
			{
				if (a[i][j][l] &&
				   (
				   	(a[i+1][j][l] + a[i-1][j][l] == 2)||
				   	(a[i][j+1][l] + a[i][j-1][l] == 2)||
				   	(a[i][j][l+1] + a[i][j][l-1] == 2)||
				   	(a[i-1][j][l] + a[i][j+1][l] == 2 && a[i-1][j+1][l] == 0)||
				   	(a[i-1][j][l] + a[i][j][l+1] == 2 && a[i-1][j][l+1] == 0)||
				   	(a[i][j-1][l] + a[i+1][j][l] == 2 && a[i+1][j-1][l] == 0)||
				   	(a[i][j-1][l] + a[i][j][l+1] == 2 && a[i][j-1][l+1] == 0)||
				   	(a[i][j][l-1] + a[i+1][j][l] == 2 && a[i+1][j][l-1] == 0)||
				   	(a[i][j][l-1] + a[i][j+1][l] == 2 && a[i][j+1][l-1] == 0)
   				   )
				)
				 ans++;
				
			}
	cout << ans << endl;
	return 0;
}