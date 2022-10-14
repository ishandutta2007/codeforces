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
#define N 100500
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,a[15][15],i,j,k,l,x,y,z,ans;
ll dp[1005][1005][5];
char c[5][1005][1005];
string pre[300];
ll xt,yt,xm,ym;
vector<pair<ll, pii> > f;
bool check_up(char c)
{
	return (c == '+' || c == '|' || c == '^' || c == 'R' || c == 'D' || c == 'L');
}
bool check_down(char c)
{
	return (c == '+' || c == '|' || c == 'v' || c == 'R' || c == 'U' || c == 'L');
}
bool check_right(char c)
{
	return (c == '+' || c == '-' || c == '>' || c == 'U' || c == 'D' || c == 'L');
}
bool check_left(char c)
{
	return (c == '+' || c == '-' || c == '<' || c == 'R' || c == 'D' || c == 'U');
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	pre['+'] = "+++";
	pre['-'] = "|-|";
	pre['|'] = "-|-";
	pre['^'] = ">v<";
	pre['>'] = "v<^";
	pre['<'] = "^>v";
	pre['v'] = "<^>";
	pre['L'] = "URD";
	pre['U'] = "RDL";
	pre['R'] = "DLU";
	pre['D'] = "LUR";
	pre['*'] = "***";
	cin >> n >> m;
	for (i = 0; i < n; i++)
		scanf("%s", c[0][i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			for (k = 1; k < 4; k++)
				c[k][i][j] = pre[c[0][i][j]][k-1];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < 4; k++)
				dp[i][j][k] = (ll)1e+18;
	cin >> xt >> yt >> xm >> ym;
	xt--;
	yt--;
	xm--;
	ym--;
	f.push_back(mp(0,mp(xt,yt)));
	dp[xt][yt][0] = 0;
	i = 0;
	while (i < f.size())
	{
		ll x = f[i].Y.X;
		ll y = f[i].Y.Y;
		ll st = f[i].X;
		i++;
		ll stx = st;
		//cout << x << " " << y << " " << st << " " << dp[x][y][st] << endl;
		for (j = 0; j < 1; j++)
		{
			stx++;
			stx %= 4;
			if (dp[x][y][stx] == (ll)1e+18)
			{
				dp[x][y][stx] = dp[x][y][st] + 1;
				f.push_back(mp(stx,mp(x,y)));
			}
		}
		if (y > 0 && check_left(c[st][x][y]) && check_right(c[st][x][y-1]) && dp[x][y-1][st] == (ll)1e+18)
		{
			dp[x][y-1][st] = dp[x][y][st] + 1;
			f.push_back(mp(st,mp(x,y-1)));
		}
		if (y+1 < m && check_right(c[st][x][y]) && check_left(c[st][x][y+1]) && dp[x][y+1][st] == (ll)1e+18)
		{
			dp[x][y+1][st] = dp[x][y][st] + 1;
			f.push_back(mp(st,mp(x,y+1)));
		}
		if (x > 0 && check_up(c[st][x][y]) && check_down(c[st][x-1][y]) && dp[x-1][y][st] == (ll)1e+18)
		{
			dp[x-1][y][st] = dp[x][y][st] + 1;
			f.push_back(mp(st,mp(x-1,y)));
		}
		if (x+1 < n && check_down(c[st][x][y]) && check_up(c[st][x+1][y]) && dp[x+1][y][st] == (ll)1e+18)
		{
			dp[x+1][y][st] = dp[x][y][st] + 1;
			f.push_back(mp(st,mp(x+1,y)));
		}
	}
	ll ans = (ll)1e+18;
	for (i = 0; i < 4; i++)
		ans = min(ans, dp[xm][ym][i]);
	if (ans == (ll)1e+18)
	   cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}