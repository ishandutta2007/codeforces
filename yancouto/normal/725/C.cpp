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
char s[110], g[2][100];

int main() {
	int i, j, k;
	scanf("%s", s);
	for(i = 0; i < 27; i++)
		for(j = i + 1; j < 27; j++) {
			if(s[i] != s[j]) continue;
			if(j == i + 1) { puts("Impossible"); return 0; }
			int u, d;
			if((j - i) % 2) {
				int x = (j - i - 1) / 2; assert(x >= 1);
				for(k = 0; k <= x; k++)
					g[0][12 - x + k] = s[i + k];
				for(k = 0; k < x; k++)
					g[1][12 - k] = s[i + x + 1 + k];
				u = 12 - x - 1;
				d = 12 - x;
			} else {
				int x = ((j - i) / 2 - 1);
				for(k = 0; k <= x; k++)
					g[0][12 - x + k] = s[i + k];
				for(k = 0; k <= x; k++)
					g[1][12 - k] = s[i + x + 1 + k];
				u = 12 - x - 1;
				d = 12 - x - 1;
			}
			int G = 0;
			for(i--; i >= 0; i--) {
				if(G == 0 && u < 0) u = 0, G = 1;
				g[G][u] = s[i];
				if(G) u++;
				else u--;
			}
			G = 1;
			for(j++; j < 27; j++) {
				if(G == 1 && d < 0) d = 0, G = 0;
				g[G][d] = s[j];
				if(G) d--;
				else d++;
			}
			puts(g[0]); puts(g[1]);
			return 0;
		}
}