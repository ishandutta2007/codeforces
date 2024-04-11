#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define N 2222
#define C 32
#define M 65536

using namespace std;

int n, x, qb, qe;
pair<int, int> v[N * N];
unsigned int a[N][N / C + 1], b[N][N / C + 1];
int md[N], mv[N];
vector<int> g[M + 500];

int main() {
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < M; i++) {
	for (int j = 0; j < 16; j++)
	    if ((i & (1 << j)) != 0)
		g[i].push_back(j);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	mv[i] = i / C;
	md[i] = i % C;
    }
    qe = -1;
    for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++) {
	    char c = getchar();
	    while ((c < '0') || (c > '9'))
		c = getchar();
	    int x = 0;
	    while ((c >= '0') && (c <= '9')) {
		x = x * 10 + c - '0';
		c = getchar();
	    }
	    if (x != 0) {
		a[i][j / C] += (1 << (j % C));
		b[j][i / C] += (1 << (i % C));
		qe++;
		v[qe] = make_pair(i, j);
	    }
	}
    int qb = 0;
    while ((qb <= qe) && (qe + 1 < n * n)) {
	int x = v[qb].first, y = v[qb].second;
	qb++;
	for (int i = 0; i <= n / C; i++) {
	    int nw = (a[x][i] | a[y][i]);
	    if (nw != a[x][i]) {
		int mt = ((nw ^ a[x][i]) & (M - 1));
		int yy = C * i;
		for (int j = 0; j < g[mt].size(); j++) {
		    qe++;
		    v[qe] = make_pair(x, yy + g[mt][j]);
		    b[yy + g[mt][j]][mv[x]] |= (1 << (md[x]));
		}
		mt = ((nw ^ a[x][i]) >> 16);
		for (int j = 0; j < g[mt].size(); j++) {
		    qe++;
		    v[qe] = make_pair(x, yy + 16 + g[mt][j]);
		    b[yy + 16 + g[mt][j]][mv[x]] |= (1 << (md[x]));
		}
	    }
	    a[x][i] = nw;

	    nw = (b[y][i] | b[x][i]);
	    if (nw != b[y][i]) {
		int mt = ((nw ^ b[y][i]) & (M - 1));
		int xx = C * i;
		for (int j = 0; j < g[mt].size(); j++) {
		    qe++;
		    v[qe] = make_pair(xx + g[mt][j], y);
		    a[xx + g[mt][j]][mv[y]] |= (1 << (md[y]));
		}
		mt = ((nw ^ b[y][i]) >> 16);
		for (int j = 0; j < g[mt].size(); j++) {
		    qe++;
		    v[qe] = make_pair(xx + 16 + g[mt][j], y);
		    a[xx + 16 + g[mt][j]][mv[y]] |= (1 << md[y]);
		}
	    }
	    b[y][i] = nw;
      	}
    }
    //    printf("%d\n", qe);
    if (qe + 1 == n * n) {
	puts("YES");
    } else {
	puts("NO");
    }
}