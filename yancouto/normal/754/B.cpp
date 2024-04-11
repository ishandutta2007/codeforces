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

int n;
int di[] = { 1, 0, 1,  1};
int dj[] = { 0, 1, 1, -1};
char g[10][10];

bool win() {
	int i, j, d, k;
	for(d = 0; d < 4; d++)
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++) {
				if(i + di[d] * 2 < 0 || i + di[d] * 2 >= 4 || j + dj[d] * 2 < 0 || j + dj[d] * 2 >= 4) continue;
				for(k = 0; k <= 2 && g[i + di[d] * k][j + dj[d] * k] == 'x'; k++);
				if(k == 3) return true;
			}
	return false;
}

int main() {
	int i, j;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			scanf(" %c", &g[i][j]);
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++) {
			if(g[i][j] != '.') continue;
			g[i][j] = 'x';
			if(win()) { puts("YES"); return 0; }
			g[i][j] = '.';
		}
	puts("NO");
}