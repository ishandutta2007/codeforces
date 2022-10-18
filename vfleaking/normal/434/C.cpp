#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

// mod
const int Mod = 1000000007;

inline int modinv(const int &a)
{
	int x1 = 1, x2 = 0, x3 = Mod;
	int y1 = 0, y2 = 1, y3 = a;
    while (y3 != 1)
    {
        int k = x3 / y3;
        x1 -= y1 * k, x2 -= y2 * k, x3 -= y3 * k;
        swap(x1, y1), swap(x2, y2), swap(x3, y3);
    }
	return y2 >= 0 ? y2 : y2 + Mod;
}
inline int modadd(const int &a, const int &b)
{
	int res = a + b;
	return res >= Mod ? res - Mod : res;
}
inline int modsub(const int &a, const int &b)
{
	int res = a - b;
	return res < 0 ? res + Mod : res;
}
inline int modmul(const int &a, const int &b)
{
	return (s64)a * b % Mod;
}
inline int moddiv(const int &a, const int &b)
{
	return modmul(a, modinv(b));
}

inline int& modaddto(int &a, const int &b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
	return a;
}
inline int& modsubto(int &a, const int &b)
{
	a -= b;
	if (a < 0)
		a += Mod;
	return a;
}
inline int& modmulto(int &a, const int &b)
{
	a = modmul(a, b);
	return a;
}
inline int& moddivto(int &a, const int &b)
{
	a = moddiv(a, b);
	return a;
}

const int MaxM = 20;
const int MaxL = 200;
const int MaxNAC = 201;
const int MaxK = 500;

int m;

struct ac_node
{
	ac_node *next[MaxM];
	ac_node *fail;
	int val;
};
ac_node ac_pool[MaxNAC], *ac_tail = ac_pool;

ac_node *ac_root;

void ac_build()
{
	int que_n = 0;
	static ac_node *que[MaxNAC];
	
	que[que_n++] = ac_root;
	for (int i = 0; i < que_n; i++)
	{
		ac_node *p = que[i];
		for (int c = 0; c < m; c++)
			if (p->next[c])
			{
				ac_node *f = p->fail;
				while (f && !f->next[c])
					f = f->fail;
				p->next[c]->fail = f ? f->next[c] : ac_root;
				p->next[c]->val += p->next[c]->fail->val;
				que[que_n++] = p->next[c];
			}
	}

	for (int i = que_n - 1; i >= 0; i--)
	{
		ac_node *p = que[i];
		for (int c = 0; c < m; c++)
			if (!p->next[c])
			{
				ac_node *f = p->fail;
				while (f && !f->next[c])
					f = f->fail;
				p->next[c] = f ? f->next[c] : ac_root;
			}
	}
}

int getVal(int len, int *a)
{
	int val = 0;
	ac_node *p = ac_root;
	for (int i = 0; i < len; i++)
		p = p->next[a[i]], val += p->val;
	return val;
}

int cK;

int f[MaxL + 1][MaxNAC][MaxK];
void init()
{
	int nAc = ac_tail - ac_pool;
	for (int i = 0; i < nAc; i++)
	{
		ac_node *p = ac_pool + i;
		if (p->val <= cK)
			f[0][i][p->val] = 1;
	}
	for (int l = 1; l <= MaxL; l++)
		for (int i = 0; i < nAc; i++)
		{
			ac_node *p = ac_pool + i;
			for (int k = p->val; k <= cK; k++)
				for (int c = 0; c < m; c++)
					modaddto(f[l][i][k], f[l - 1][p->next[c] - ac_pool][k - p->val]);
		}
	for (int l = 0; l <= MaxL; l++)
		for (int i = 0; i < nAc; i++)
			for (int k = 1; k <= cK; k++)
				modaddto(f[l][i][k], f[l][i][k - 1]);
}

int query(int len, int *a)
{
	int res = 0;
	for (int l = 1; l < len; l++)
		for (int c = 1; c < m; c++)
			modaddto(res, f[l - 1][ac_root->next[c] - ac_pool][cK]);

	int restK = cK;
	ac_node *p = ac_root;
	for (int s = 0; s < len; s++)
	{
		if (p->val > restK)
			break;
		for (int c = s == 0 ? 1 : 0; c < a[s]; c++)
			modaddto(res, f[len - s - 1][p->next[c] - ac_pool][restK - p->val]);
		restK -= p->val;
		p = p->next[a[s]];
	}
	return res;
}

int main()
{
	int n;
	int qL_n;
	static int qL[MaxL];
	int qR_n;
	static int qR[MaxL];

	cin >> n >> m >> cK;
	scanf("%d", &qL_n);
	for (int i = 0; i < qL_n; i++)
		scanf("%d", &qL[i]);
	scanf("%d", &qR_n);
	for (int i = 0; i < qR_n; i++)
		scanf("%d", &qR[i]);

	ac_root = ac_tail++;
	for (int j = 0; j < n; j++)
	{
		ac_node *p = ac_root;

		int len;
		scanf("%d", &len);
		for (int k = 0; k < len; k++)
		{
			int c;
			scanf("%d", &c);
			if (!p->next[c])
				p->next[c] = ac_tail++;
			p = p->next[c];
		}
		int val;
		scanf("%d", &val);
		p->val += val;
	}

	ac_build();

	init();

	int res = getVal(qR_n, qR) <= cK;
	modaddto(res, query(qR_n, qR));
	modsubto(res, query(qL_n, qL));
	cout << res << endl;

	return 0;
}