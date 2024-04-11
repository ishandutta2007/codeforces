#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 100;
char s[N][N][N];
int n, m;
bool g[N][N];
bool used[N];
int ord[N];
int ordSz;
int col[N];
vector<int> forCol[N];

void dfsOrd(int v) {
	used[v] = 1;
	for (int u = 0; u < n; u++) {
		if (!g[u][v]) continue;
		if (used[u]) continue;
		dfsOrd(u);
	}
	ord[ordSz++] = v;
}
void dfsCol(int v) {
	col[v] = m;
	forCol[m].push_back(v);
	for (int u = 0; u < n; u++) {
		if (!g[v][u]) continue;
		if (col[u] == -1)
			dfsCol(u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			g[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfsOrd(i);
	reverse(ord, ord + ordSz);
	for (int v = 0; v < n; v++)
		col[v] = -1;
	for (int i = 0; i < ordSz; i++) {
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsCol(v);
		m++;
	}
	int L = max(n, m * (m - 1));
	for (int z = 0; z < 3 * m; z++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < L; y++) {
				s[x][y][z] = '.';
				if (z % 3 == 0 || x == 1 || (x == 2 && y % 2 == 1))
					s[x][y][z] = '#';
	}
	int id = 0;
	for (int v = 0; v < m; v++) {
		for (int i = 0; i < (int)forCol[v].size(); i++)
			s[0][i][3 * v + 1] = '1' + forCol[v][i];
		for (int u = 0; u < v; u++) {
			bool hv = false;
			for (int x : forCol[v])
				for (int y : forCol[u])
					hv |= g[x][y];
			if (hv) {
				s[1][id][3 * v + 1] = s[1][id][3 * u + 1] = '.';
				s[2][id][3 * u] = '#';
				for (int i = u + 1; i <= v; i++)
					s[2][id][3 * i] = '.';
			}
			id += 2;
		}
	}
	printf("3 %d %d\n", L, 3 * m);
	for (int z = 3 * m - 1; z >= 0; z--) {
		for (int y = 0; y < L; y++) {
			for (int x = 0; x < 3; x++)
				printf("%c", s[x][y][z]);
			printf("\n");
		}
		printf("\n");
	}
	
    return 0;
}