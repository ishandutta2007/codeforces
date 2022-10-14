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
#define INF (1LL+(ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 19
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef int ll;
typedef long double ld;
using namespace std;
ll n,m,i,j,k,kk,l,r,x,y,z,ans,flag,sz,v;
ll a[1005][1005], pa[1005][1005], col[1005000], used[1000050], usd[1000500];
ll dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
ll dfs(ll x, ll y)
{
	col[sz]++;
	a[x][y] = sz;
	for (int i = 0; i < 4; i++)
		if (a[x+dirs[i][0]][y+dirs[i][1]] == 1)
			dfs(x+dirs[i][0], y+dirs[i][1]);
}
char s[1005][1005];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		scanf("%s",s[i]);
		for (j = 0; j < n; j++)
			if (s[i][j] == '.')
			   a[i+1][j+1] = 1;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			pa[i][j] = a[i][j] + pa[i-1][j] + pa[i][j-1] - pa[i-1][j-1];
	sz = 2;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (a[i][j] == 1)
			{
				dfs(i,j);
				sz++;
			}
	ll ans = 0;
	ll tmp = 0;
	for (i = 1; i <= n-k+1; i++)
		for (j = 1; j <= n-k+1; j++)
		{
			if (j == 1)
			{
				tmp = 0;
				for (l = i; l < i+k; l++)
					for (r = j; r < j+k; r++)
					{
						v = a[l][r];
						usd[v]++;
						if (usd[v] == 1)
						   tmp += col[v];
					}
			} else
			{
				for (l = i; l < i+k; l++)
					for (r = j-1; r < j; r++)
					{
						v = a[l][r];
						usd[v]--;
						if (usd[v] == 0)
						   tmp -= col[v];
					}
				for (l = i; l < i+k; l++)
					for (r = j+k-1; r < j+k; r++)
					{
						v = a[l][r];
						usd[v]++;
						if (usd[v] == 1)
						   tmp += col[v];
					}
			}
			ll sum = tmp;
			sum += k*k-(pa[i+k-1][j+k-1] - pa[i-1][j+k-1] - pa[i+k-1][j-1] + pa[i-1][j-1]);
			ll val = i*(n+3)+j;
			for (l = j; l < j+k; l++)
			{
				v = a[i-1][l];
				if (used[v] != val && !usd[v])
				{
					used[v] = val;
					sum += col[v];
				}
				v = a[i+k][l];
				if (used[v] != val && !usd[v])
				{
					used[v] = val;
					sum += col[v];
				}
			}

			for (l = i; l < i+k; l++)
			{
				v = a[l][j-1];
				if (used[v] != val && !usd[v])
				{
					used[v] = val;
					sum += col[v];
				}
				v = a[l][j+k];
				if (used[v] != val && !usd[v])
				{
					used[v] = val;
					sum += col[v];
				}
			}
			ans = max(ans,sum);

			if (j == n-k+1)
			{
				for (l = i; l < i+k; l++)
					for (r = j; r < j+k; r++)
					{
						v = a[l][r];
						usd[v]--;
					}
			}
			//cout << i << " " << j << " " << sum << endl;
		}
		cout << ans << endl;
	return 0;
}