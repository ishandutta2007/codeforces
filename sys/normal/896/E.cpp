#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1000005, lim = 100001;
int n, m, per, bloc, a[Maxn], fa[Maxn * 32], siz[Maxn * 32], maxi[Maxn], shift[Maxn], bel[Maxn], root[321][Maxn / 10 + 5];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		fa[b] = a;
		siz[a] += siz[b], siz[b] = 0;
	}
}
void modify(int lt, int rt, int x)
{
	int posl = bel[lt], posr = bel[rt];
	maxi[posl] = maxi[posr] = 0;
	if (posl == posr)
	{
		for (int i = (posl - 1) * per + 1; i <= min(n, posl * per); i++)
		{
			int tmp = get_fa(i) - root[posl][1] + 1 + shift[posl];
			if (i >= lt && i <= rt && tmp > x) tmp -= x;
			maxi[posl] = max(maxi[posl], tmp - shift[posl]);
			siz[get_fa(i)]--;
			fa[i] = i, siz[i] = 1;
			merge(root[posl][tmp - shift[posl]], i);
		}
		return ;
	}
	for (int i = (posl - 1) * per + 1; i <= posl * per; i++)
	{
		int tmp = get_fa(i) - root[posl][1] + 1 + shift[posl];
		if (i >= lt && tmp > x) tmp -= x;
		maxi[posl] = max(maxi[posl], tmp - shift[posl]);
		siz[get_fa(i)]--;
		fa[i] = i, siz[i] = 1;
		merge(root[posl][tmp - shift[posl]], i);
	}
	for (int i = (posr - 1) * per + 1; i <= min(n, posr * per); i++)
	{
		int tmp = get_fa(i) - root[posr][1] + 1 + shift[posr];
		if (i <= rt && tmp > x) tmp -= x;
		maxi[posr] = max(maxi[posr], tmp - shift[posr]);
		siz[get_fa(i)]--;
		fa[i] = i, siz[i] = 1;
		merge(root[posr][tmp - shift[posr]], i);
	}
	for (int i = posl + 1; i <= posr - 1; i++)
	{
		if (maxi[i] + shift[i] <= x) continue;
		if (x * (long long) x > lim)
		{
			maxi[i] = 0;
			for (int j = (i - 1) * per + 1; j <= i * per; j++)
			{
				int tmp = get_fa(j) - root[i][1] + 1 + shift[i];
				if (tmp > x) tmp -= x;
				maxi[i] = max(maxi[i], tmp - shift[i]);
				siz[get_fa(j)]--;
				fa[j] = j, siz[j] = 1;
				merge(root[i][tmp - shift[i]], j);
			}
		}
		else
		{
			for (int j = 1; j <= x; j++)
			{
				if (siz[get_fa(root[i][j - shift[i]])]) maxi[i] = max(maxi[i], j + x - shift[i]);
				merge(root[i][j - shift[i] + x], root[i][j - shift[i]]);
			}
			shift[i] -= x;
		}
	}
}
int ask(int lt, int rt, int x)
{
	int result = 0, posl = bel[lt], posr = bel[rt];
	if (posl == posr)
	{
		for (int i = lt; i <= rt; i++)
			result += (get_fa(i) - root[posl][1] + 1 + shift[posl]) == x;
		return result;
	}
	for (int i = lt; i <= bel[lt] * per; i++)
		result += (get_fa(i) - root[posl][1] + 1 + shift[posl]) == x;
	for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
		result += (get_fa(i) - root[posr][1] + 1 + shift[posr]) == x;
	for (int i = posl + 1; i <= posr - 1; i++)
		if (x - shift[i] <= lim) result += siz[get_fa(root[i][x - shift[i]])];
	return result;
}
int main()
{
	scanf("%d%d", &n, &m);
	bloc = sqrt(n), per = (n + bloc - 1) / bloc;
	int ct = n;
	for (int i = 1; i <= bloc; i++)
		for (int j = 1; j <= lim; j++)
			root[i][j] = ++ct, fa[ct] = ct;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		bel[i] = (i - 1) / per + 1, fa[i] = i, siz[i] = 1;
		maxi[bel[i]] = max(maxi[bel[i]], a[i]);
		merge(root[bel[i]][a[i]], i);
	}
	for (int i = 1; i <= m; i++)
	{
		int opt, l, r, x;
		scanf("%d%d%d%d", &opt, &l, &r, &x);
		if (l > r) swap(l, r);
		if (opt == 1)
			modify(l, r, x);
		else printf("%d\n", ask(l, r, x));
	}
	return 0;
}