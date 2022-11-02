#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % 1000000009ll; }
const int N = 3000;

ll pd[N];
char s[N], t[N];
int eq[N][N], eq2[N][N], opt[N], rev[N];

bool pos(int i, int j) {
	return (rev[i]? eq2 : eq)[i][opt[i]] >= j - i + 1;
}
int n, m;
void print_pos(int i, int j) {
	int beg = opt[i] + 1, end = opt[i] + j - i + 1;
	if(rev[i]) beg = m - opt[i], end = m - opt[i] - (j - i);
	printf("%d %d\n", beg, end);
}

void build(int i) {
	for(int j = i; t[j]; j++) {
		if(pos(i, j) && pd[i] == pd[j + 1] + 1) {
			print_pos(i, j);
			build(j + 1);
			return;
		}
	}
}

int main() {
	int i, j;
	scanf("%s %s", s, t);
	n = strlen(t), m = strlen(s);
	for(i = n - 1; i >= 0; i--)
		for(j = m - 1; j >= 0; j--) {
			if(t[i] == s[j])
				eq[i][j] = 1 + eq[i + 1][j + 1];
			if(t[i] == s[m - 1 - j])
				eq2[i][j] = 1 + eq2[i + 1][j + 1];
		}
	for(i = 0; i < n; i++) {
		int best = 0, best2 = 0;
		for(j = 1; j < m; j++) {
			if(eq[i][j] > eq[i][best])
				best = j;
			if(eq2[i][j] > eq2[i][best2])
				best2 = j;
		}
		if(eq[i][best] >= eq2[i][best2])
			opt[i] = best,
			rev[i] = 0;
		else opt[i] = best2,
			rev[i] = 1;
	}
	for(i = n - 1; i >= 0; i--) {
		pd[i] = 1000000000;
		for(j = i; j < n; j++)
			if(pos(i, j))
				pd[i] = min(pd[i], pd[j + 1] + 1);
	}
	if(pd[0] >= 1000000000) { puts("-1"); return 0; }
	printf("%d\n", pd[0]);
	build(0);
}