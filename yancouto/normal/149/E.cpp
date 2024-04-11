#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 101009;

char s[MAX], s2[MAX];
int z[MAX];
void z_func() {
	int l = 0, r = 0;
	for(int i = 1; s[i]; i++) {
		if(i > r) {
			l = r = i;
			while(s[r] == s[r - i]) r++;
			z[i] = r-- - l;
			continue;
		}
		int k = i - l;
		if(z[k] < r - i + 1) { z[i] = z[k]; continue; }
		l = i;
		while(s[r] == s[r - i]) r++;
		z[i] = r-- - l;
	}
}
int b[MAX];
int main() {
	int i, n, m, p, tot = 0;
	scanf("%s %d", s2, &m); n = strlen(s2);
	while(m--) {
		scanf("%s", s); p = strlen(s);
		if(p == 1) continue;
		s[p] = '|';
		memcpy(s + p + 1, s2, n + 1);
		for(i = 0; i <= n; i++)
			b[i] = p;
		z_func();
		for(i = 0; i < n; i++) {
			b[i + z[i + p + 1]] = min(b[i + z[i + p + 1]], p - z[i + p + 1]);
			if(i) b[i] = min(b[i], b[i - 1]);
			if(z[i + p + 1] == p) break;
		}
		if(i < n) { tot++; continue; }
		for(i = n - 2; i >= 0; i--)
			b[i] = min(b[i], b[i + 1] + 1);
		reverse(s, s + p);
		reverse(s + p + 1, s + p + 1 + n);
		z_func();
		for(i = 0; i < n; i++)
			if(z[i + p + 1] >= b[n - 1 - i - z[i + p + 1] + 1])
				break;
		tot += i < n;
	}
	printf("%d\n", tot);
}