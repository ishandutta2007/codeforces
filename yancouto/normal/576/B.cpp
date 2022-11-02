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

int p[100009], cyc[100009], seen[100009];
int main() {
	int i, j, n;
	scanf("%d", &n);
	int h1 = -1;
	for(i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		if(--p[i] == i) h1 = i;
	}
	if(h1 >= 0) {
		puts("YES");
		for(i = 0; i < n; i++)
			if(i != h1)
				printf("%d %d\n", h1 + 1, i + 1);
		return 0;
	}
	int h2 = -1;
	for(i = 0; i < n; i++) {
		if(seen[i]) continue;
		int j = i, sz = 0;
		while(!seen[j]) {
			seen[j] = true;
			sz++;
			j = p[j];
		}
		if(sz & 1) {
			puts("NO");
			return 0;
		}
		if(sz == 2) h2 = i;
		cyc[i] = sz;
	}
	if(h2 == -1) { puts("NO"); return 0; }
	puts("YES");
	printf("%d %d\n", h2 + 1, p[h2] + 1);
	for(i = 0; i < n; i++) {
		if(!cyc[i] || i == h2) continue;
		int g = h2, h = i;
		for(j = 0; j < cyc[i]; j++) {
			printf("%d %d\n", g + 1, h + 1);
			g = p[g]; h = p[h];
		}
	}
}