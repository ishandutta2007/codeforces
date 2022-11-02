#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 2004;
char g[MAX][MAX];
pii st[MAX * MAX]; int sn;

int dx[4] =  {-1 ,   1,    0,   0};
int dy[4] =  {0  ,   0,   -1,   1};
char s1[4] = {'v', '^',  '>', '<'};
char s2[4] = {'^', 'v',  '<', '>'};
int deg[MAX][MAX];
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && g[i][j]; }

int main() {
	int n, m, i, j, d, d2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf(" %c", &g[i][j]);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) { 
			if(g[i][j] != '.') continue;
			for(d = 0; d < 4; d++) {
				int ni = i + dx[d], nj = j + dy[d];
				if(valid(ni, nj) && g[ni][nj] == '.') deg[i][j]++;
			}
			if(deg[i][j] == 1) st[sn++] = pii(i, j);
		}
	while(sn) {
		i = st[--sn].fst; j = st[sn].snd;
		for(d = 0; d < 4; d++) {
			int ni = i + dx[d], nj = j + dy[d];
			if(!valid(ni, nj) || g[ni][nj] != '.') continue;
			g[i][j] = s1[d];
			g[ni][nj] = s2[d];
			for(d2 = 0; d2 < 4; d2++) {
				int nii = ni + dx[d2], njj = nj + dy[d2];
				if(!valid(nii, njj) || g[nii][njj] != '.') continue;
				if(--deg[nii][njj] == 1) st[sn++] = pii(nii, njj);
			}
		}
	}
	bool ok = true;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(g[i][j] == '.')
				ok = false;
	if(!ok) { puts("Not unique"); return 0; }
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			putchar(g[i][j]);
		putchar('\n');
	}
}