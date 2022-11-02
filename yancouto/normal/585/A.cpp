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

const int MAX = 4009;
int v[MAX], d[MAX], p[MAX], n;

void red(int i, int v) {
	if(p[i] < 0) return;
	p[i] -= v;
	if(p[i] < 0)
		for(int j = i + 1; j < n; j++)
			red(j, d[i]);
}
int seen[MAX], val[MAX];
int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &v[i], &d[i], &p[i]);
	int st[4009], sn = 0;
	for(i = 0; i < n; i++) {
		if(p[i] < 0) continue;
		st[sn++] = i + 1;
		for(j = k = 0; i + j + 1 < n && v[i] - k > 0; j++)
			if(p[i + j + 1] >= 0)
				seen[i + j + 1] = i + 1, val[i + j + 1] = v[i] - k++;
		for(j = i + 1; j < n; j++)
			if(seen[j] == i + 1)
				red(j, val[j]);
	}
	printf("%d\n", sn);
	for(i = 0; i < sn; i++)
		printf("%d ", st[i]);
	putchar('\n');
}