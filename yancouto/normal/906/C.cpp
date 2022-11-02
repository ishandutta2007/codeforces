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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int pos;

int adj[30], adj2[30];

inline bool test(int ch) {
	for(int i = 0; i < n; i++)
		if(adj[i] != ((1 << n) - 1))
			return false;
	return true;
	for(int i = 0; i < n; i++)
		adj2[i] = adj[i];
	int och = ch;
	while(ch) {
		int i = __builtin_ctz(ch);
		ch ^= (1 << i);
		int x = adj2[i];
		while(x) {
			int j = __builtin_ctz(x);
			//if(och == 6) printf("%d -> %d\n", x, j);
			x ^= (1 << j);
			//if(och == 6) printf("[%d,%d] %d->%d\n", i, j, adj2[j], adj2[j] | adj2[i]);
			adj2[j] |= adj2[i];
		}
	}
	for(int i = 0; i < n; i++)
		if(adj2[i] != ((1 << n) - 1))
			return false;
	return true;
}

int bk[30][30];

void go(int i, int ch, int left) {
	if(__builtin_popcount(ch) >= __builtin_popcount(pos)) return;
	if(i == n) {
		if(test(ch)) pos = ch;
		return;
	}
	go(i + 1, ch, left);
	if(left > 0) {
		int x = adj[i];
		while(x) {
			int j = __builtin_ctz(x);
			x ^= (1 << j);
			bk[i][j] = adj[j];
			adj[j] |= adj[i];
		}
		go(i + 1, ch | (1 << i), left - 1);
		x = adj[i];
		while(x) {
			int j = __builtin_ctz(x);
			x ^= (1 << j);
			adj[j] = bk[i][j];
		}
	}
}

int main() {
	int i, j, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) adj[i] = (1 << i);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a] |= (1 << b);
		//printf("adj[%d] |= (1 << %d)\n", a, b);
		adj[b] |= (1 << a);
		//printf("adj[%d] |= (1 << %d)\n", b, a);
	}
	for(i = 0; i < n && adj[i] == ((1 << n) - 1); i++);
	if(i == n) {
		puts("0");
		return 0;
	}
	pos = (1 << n) - 1;
	go(0, 0, n);
	printf("%d\n", int(__builtin_popcount(pos)));
	for(i = 0; i < n; i++)
		if((pos >> i) & 1)
			printf("%d ", i + 1);
	putchar('\n');
}