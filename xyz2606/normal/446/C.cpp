#include<cstring>
#include<cstdio>
int f[300004], a[300001], n, m, id, x, y, modulo = 1000000009;
int _calcnum(int f1, int f2, int idx)
{
	return ((long long)f[idx] * f1 + (long long)f[idx + 1] * f2) % modulo;
}
void pls(int & a, int b)
{
	a += b;
	if(a >= modulo) a -= modulo;
	else if(a < 0) a += modulo;
}
struct node
{
	int f1, f2, sum, l, r;
	node * s[2];
	node(int l, int r) : l(l), r(r)
	{
		f1 = f2 = 0;
		if(l == r)
		{
			s[0] = s[1] = 0;
			sum = a[l];
		}else
		{
			s[0] = new node(l, (l + r) / 2);
			s[1] = new node((l + r) / 2 + 1, r);
			sum = s[0]->sum + s[1]->sum;
			if(sum >= modulo) sum -= modulo;
		}
	}
	void down()
	{
		if(f1 or f2)
		{
			pls(s[0]->f1, f1);
			pls(s[0]->f2, f2);
			pls(s[0]->sum, _calcnum(f1, f2, s[0]->r - s[0]->l + 1) - f2);
			pls(s[1]->f1, _calcnum(f1, f2, s[0]->r - s[0]->l));
			pls(s[1]->f2, _calcnum(f1, f2, s[0]->r - s[0]->l + 1));
			s[1]->sum = sum - s[0]->sum;
			if(s[1]->sum < 0) s[1]->sum += modulo;
			f1 = f2 = 0;
		}
	}
	void inc()
	{
		if(l > y or r < x) return;
		else if(x <= l and r <= y)
		{
			pls(f1, f[l - x + 1]);
			pls(f2, f[l - x + 2]);
			pls(sum, f[r - x + 3] - f[l - x + 2]);
		}else
		{
			down();
			s[0]->inc(); s[1]->inc();
			sum = s[0]->sum + s[1]->sum;
			if(sum >= modulo) sum -= modulo;
		}
	}
	int getsum()
	{
		if(l > y or r < x) return 0;
		else if(x <= l and r <= y) return sum;
		else
		{
			down();
			int rtn = s[0]->getsum() + s[1]->getsum();
			return rtn >= modulo?rtn - modulo:rtn;
		}
	}
} *root;
int main()
{
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= 300003; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= modulo) f[i] -= modulo;
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	root = new node(1, n);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &id, &x, &y);
		if(id == 1)
			root->inc();
		else
			printf("%d\n", root->getsum());
	}
	fclose(stdin);
	return 0;
}