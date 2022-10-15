#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int l, idx[222222], t, cl, cl1, cl2, nblg, bd1[222222], bd2[222222], v, p, blg[222222], tim[222222], y, a[111111];
struct recq
{
	int v, p;
} q[222222];
struct recedge
{
	int y, next;
} edge[444444];
void build(int x, int y)
{
	edge[++l].y = y;
	edge[l].next = idx[x];
	idx[x] = l;
}
void ps(int x)
{
	tim[bd1[++cl1] = bd2[++cl2] = q[++cl].v = x] = ++t;
	q[cl].p = idx[x];
}
int main()
{
	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	map<int, int> mp;
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]] = i;
	}
	l = 0; fill_n(idx + 1, 2 * n, 0);
	for(int i(1); i <= n; i++) {
		if(mp.count(A - a[i])) {
			build(i * 2 - 1, mp[A - a[i]] * 2 - 1);
			build(mp[A - a[i]] * 2, i * 2);
		}else {
			build(i * 2 - 1, i * 2);
		}
		if(mp.count(B - a[i])) {
			build(i * 2, mp[B - a[i]] * 2);
			build(mp[B - a[i]] * 2 - 1, i * 2 - 1);
		}else {
			build(i * 2, i * 2 - 1);
		}
	}
	t = cl = cl1 = cl2 = nblg = 0;
	fill_n(blg + 1, 2 * n, 0);
	fill_n(tim + 1, 2 * n, 0);
	for(int i = 1; i <= 2 * n; i++) if(!blg[i])
	{
		ps(i);
		while(cl)
		{
			v = q[cl].v;
			q[cl].p = edge[p = q[cl].p].next;
			if(p)
			{
				if(!blg[y = edge[p].y])
					if(!tim[y])
						ps(y);
					else
						while(tim[bd2[cl2]] > tim[y]) cl2--;
			}else
			{
				if(bd2[cl2] == v)
				{
					blg[v] = ++nblg;
					//printf("blg[%d] = %d\n", v, blg[v]);
					while(bd1[cl1] != v) blg[bd1[cl1--]] = nblg;
					cl1--; cl2--;
				}
				cl--;
			}
		}
	}
	bool flag(true);
	for(int i(1); i <= n and flag; i++) {
		if(blg[i * 2 - 1] == blg[2 * i]) {
			flag = false;
		}
	}
	if(!flag)
		puts("NO");
	else {
		puts("YES");
		for(int i(1); i <= n; i++) {
			printf("%d%c", blg[i * 2 - 1] < blg[i * 2]?0:1, i == n?'\n':' ');
		}
	}
	fclose(stdin);
	return 0;
}