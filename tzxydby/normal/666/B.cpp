#include<bits/stdc++.h>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 3001;

int d[MAXN][MAXN];
int a[MAXN][5];
int b[MAXN][5];
vector <int> e[MAXN];

int q[MAXN], qe;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int ac, bc;
		cin >> ac >> bc;
		ac--, bc--;
		e[ac].push_back(bc);
	}
	for (int iter = 0; iter < n; iter++)
	{
		for (int i = 0; i < n; i++) d[iter][i] = MAXN;
		d[iter][iter] = 0;
		qe = 1, q[0] = iter;
		for (int i = 0; i < qe; i++)
		{
			int v = q[i];
			for (int j = 0; j < e[v].size(); j++)
			{
				if (d[iter][e[v][j]] == MAXN)
				{
					d[iter][e[v][j]] = d[iter][v] + 1;
					q[qe++] = e[v][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++) a[i][j] = b[i][j] = i;
		d[i][i] = -5 * MAXN;
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] == MAXN) d[i][j] = -4 * MAXN;
			if (d[j][i] == MAXN) d[j][i] = -4 * MAXN;
			for (int it = 3; it >= 0; it--)
			{
				if (d[i][a[i][it]] < d[i][j])
				{
					a[i][it + 1] = a[i][it];
					a[i][it] = j;
				}
				if (d[b[i][it]][i] < d[j][i])
				{
					b[i][it + 1] = b[i][it];
					b[i][it] = j;
				}
			}
		}
	}
	int ans = -5 * MAXN, aa, ai, aj, ab;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			for (int l1  = 0; l1 < 4; l1++)
			{
				if (j == a[i][l1]) continue;
				for (int l2 = 0; l2 < 4; l2++)
				{
					if ((i == b[j][l2]) || (b[j][l2] == a[i][l1])) continue;
					int nd = d[b[j][l2]][j] + d[j][i] + d[i][a[i][l1]];
					if (nd > ans) ans = nd, aa = b[j][l2], ai = j, aj = i, ab = a[i][l1];
				}
			}
		}
	}
	cout << aa + 1 << " " << ai + 1 << " " << aj + 1 << " " << ab + 1 << endl;
	return 0;
}////