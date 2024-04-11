#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int Mod = 1000000007;

const int MaxN = 100000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n;
int col[MaxN + 1];
halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	cin >> n;
	for (int v = 2; v <= n; v++)
	{
		int u;
		scanf("%d", &u);
		u++;
		addEdge(u, v);
	}

	for (int v = 1; v <= n; v++)
		scanf("%d", &col[v]);

	static int f[MaxN + 1][2];

	for (int v = n; v >= 1; v--)
	{
		if (col[v] == 0)
		{
			f[v][1] = 1;
			for (halfEdge *e = adj[v]; e; e = e->next)
				f[v][1] = (s64)f[v][1] * (f[e->u][1] + f[e->u][0]) % Mod;

			int son_n = 0;
			static int son[MaxN];
			static int pre[MaxN + 1];
			static int suf[MaxN + 1];
			for (halfEdge *e = adj[v]; e; e = e->next)
				son[son_n++] = e->u;

			pre[0] = 1;
			for (int i = 0; i < son_n; i++)
				pre[i + 1] = (s64)pre[i] * (f[son[i]][0] + f[son[i]][1]) % Mod;

			suf[son_n] = 1;
			for (int i = son_n - 1; i >= 0; i--)
				suf[i] = (s64)suf[i + 1] * (f[son[i]][0] + f[son[i]][1]) % Mod;

			f[v][0] = 0;
			for (int i = 0; i < son_n; i++)
				f[v][0] = (f[v][0] + (s64)pre[i] * f[son[i]][0] % Mod * suf[i + 1] % Mod) % Mod;
		}
		else if (col[v] == 1)
		{
			f[v][1] = 0;
			f[v][0] = 1;
			for (halfEdge *e = adj[v]; e; e = e->next)
				f[v][0] = (s64)f[v][0] * (f[e->u][1] + f[e->u][0]) % Mod;
		}
	}

	cout << f[1][0] << endl;

	return 0;
}