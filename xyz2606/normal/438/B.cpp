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
using namespace std;
int n, m, a[111111];
struct recedge
{
	int y, next;
} edge[222222];
int idx[111111], l, tot, siz[111111], rela[111111], x, y, l1, v1[111111], v;
bool f[111111];
int flag[111111];
bool cmp(const pair<int, int> & a, const pair<int, int> & b)
{return a.first > b.first;}
vector<pair<int, int> > vec;
int getr(int x)
{
	int p = x, p1, p2;
	while(rela[p] != p) p = rela[p];
	p1 = p; p = x;
	while(rela[p] != p) {p2 = rela[p]; rela[p] = p1; p = p2;}
	return p1;
}
void build(int x, int y)
{
	edge[++l].y = y;
	edge[l].next = idx[x];
	idx[x] = l;
}
long long ans, ans1;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vec.push_back(make_pair(a[i], i));
	}
	l = 0; memset(idx, 0, sizeof(idx));
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		build(x, y);
		build(y, x);
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i = 1; i <= n; i++) rela[i] = i, siz[i] = 1;
	memset(f, false, sizeof(f));
	memset(flag, -1, sizeof(flag));
	ans = 0;
	for(int i = 0; i < (int)vec.size(); i++)
	{
		//printf("%d\n", vec[i].second);
		v = vec[i].second;
		f[v] = true;
		l1 = 0;
		tot = 0;
		for(int p = idx[v]; p; p = edge[p].next) if(f[edge[p].y])
		{
			y = getr(edge[p].y);
			//printf("%d %d %d\n", y, siz[y], flag[y]);
			if(flag[y] != i)
			{
				v1[++l1] = y;
				flag[y] = i;
				tot += siz[y];
			}
		}
		ans1 = 0;
		for(int j = 1; j <= l1; j++) ans1 += (long long)siz[v1[j]] * (tot - siz[v1[j]]) * a[v];
		ans += ans1 / 2;
		ans += (long long)a[v] * tot;
		//printf("%d %d\n", a[v], tot);
		for(int j = 1; j <= l1; j++) {rela[v1[j]] = v; siz[v] += siz[v1[j]]; siz[v1[j]] = 0;}
	}
	printf("%.6f\n", (double)ans * 2 / n / (n - 1));
	fclose(stdin);
	return 0;
}