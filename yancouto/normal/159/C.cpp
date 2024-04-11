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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int k;
char s1[105];
char str[200009];
int bit[27][200009];
void add(int i, int val, int b[]) {
	i += 2;
	while(i < 200009) {
		b[i] += val;
		i += (i & -i);
	}
}
int get(int i, int b[]) {
	int sum = 0; i += 2;
	while(i) {
		sum += b[i];
		i -= (i & -i);
	}
	return sum;
}

int main() {
	int i, j, siz, n, x; char c;
	scanf("%d %s", &k, s1);
	siz = strlen(s1);
	for(i = 0; i < k; i++)
		memcpy(str + i*siz, s1, siz);
	for(i = 0; i < (k*siz); i++) {
		add(i, 1, bit[str[i] - 'a']);	
	}
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %c", &x, &c);
		int l = 0, r = k*siz; int *b = bit[c - 'a'];
		while(l < r) {
			int m = (l + r)/2;
			if(get(m, b) < x) l = m + 1;
			else r = m;
		}
		str[l] = '\0';
		add(l, -1, bit[c - 'a']);
	}
	for(i = 0; i < k*siz; i++)
		if(str[i])
			putchar(str[i]);
	putchar('\n');
	return 0;
}