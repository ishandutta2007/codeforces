#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<cassert>
using namespace std;
int n, a[111111], e[1111][1111], x, y, f[1111], ans, m;
bool cmp(const pair<int, int> & a, const pair<int, int> & b)
{return a.first > b.first;}
vector<pair<int, int> > vec;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vec.push_back(make_pair(a[i], i));
	}
	memset(e, false, sizeof(e));
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		e[x][y] = e[y][x] = true;
	}
	sort(vec.begin(), vec.end(), cmp);
	memset(f, true, sizeof(f));
	ans = 0;
	for(int i = 0; i < (int)vec.size(); i++)
	{
		f[vec[i].second] = false;
		for(int j = 1; j <= n; j++) if(e[vec[i].second][j] and f[j])
			ans += a[j];
	}
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}