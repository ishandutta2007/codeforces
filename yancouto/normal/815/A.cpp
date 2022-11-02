#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, m;
int g[1123][1123];
int rows[1123], cols[1123];

void any(int mn) {
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			if(g[i][j] != mn) continue;
			for(k = 0; k < m; k++)
				if(g[i][k] != mn)
					cols[k] += g[i][k] - mn;
			for(i = 0; i < n; i++)
				if(g[i][0] > rows[i] + cols[0])
					rows[i] += g[i][0] - (rows[i] + cols[0]);
			return;
		}
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	int mn = INT_MAX;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
			mn = min(mn, g[i][j]);
		}
	if(n <= m)
		for(i = 0; i < n; i++)
			rows[i] = mn;
	else
		for(j = 0; j < m; j++)
			cols[j] = mn;
	any(mn);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(g[i][j] != rows[i] + cols[j]) {
				puts("-1");
				return 0;
			}
	printf("%d\n", accumulate(rows, rows + n, 0) + accumulate(cols, cols + m, 0));
	for(i = 0; i < n; i++)
		for(j = 0; j < rows[i]; j++)
			printf("row %d\n", i + 1);
	for(j = 0; j < m; j++)
		for(i = 0; i < cols[j]; i++)
			printf("col %d\n", j + 1);
}