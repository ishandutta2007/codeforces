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
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 300009;
int n;
int v[MAX], inv[MAX];

int bit[MAX];
int get(int i) {
	int sum = 0; i += 2;
	while(i) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}
int get(int i, int j) { return get(j) - get(i - 1); }
void add(int i, int x) {
	i += 2;
	while(i < MAX) {
		bit[i] += x;
		i += (i & -i);
	}
}

void deb() {
	return;
	for(int i = 0; i < n; i++)
		printf("%d ", v[i] + 1);
	putchar('\n');
	for(int i = 0; i < n; i++)
		printf("%d ", get(i, i));
	putchar('\n');
	puts("----------");
}

int main() {
	int i, j, q, op, x, y;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v[i]); v[i]--;
		inv[v[i]] = i;
	}
	for(i = 0; i < n - 1; i++)
		if(inv[i + 1] < inv[i])
			add(i, 1);
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d", &op, &x, &y); x--; y--;
		if(op == 1) printf("%d\n", 1 + get(x, y - 1));
		else {
			if(abs(v[x] - v[y]) == 1) {
				if(v[y] == v[x] + 1) {
					//printf("change small big\n");
					deb();
					add(v[x], 1);
					if(v[y] < n - 1 && inv[v[y] + 1] > x && inv[v[y] + 1] < y) add(v[y], -1);
					if(v[x] > 0 && inv[v[x] - 1] > x && inv[v[x] - 1] < y) add(v[x] - 1, -1);
				}
				else {
					//printf("change big small\n");
					deb();
					add(v[y], -1);
					deb();
					if(v[x] < n - 1 && inv[v[x] + 1] > x && inv[v[x] + 1] < y) add(v[x], 1);
					if(v[y] > 0 && inv[v[y] - 1] > x && inv[v[y] - 1] < y) add(v[y] - 1, 1);
				}
			} else {
				//puts("other");
				deb();
				if(v[x] > 0 && inv[v[x] - 1] > x && inv[v[x] - 1] < y) add(v[x] - 1, -1);
				if(v[x] < n - 1 && inv[v[x] + 1] > x && inv[v[x] + 1] < y) add(v[x], 1);
				if(v[y] > 0 && inv[v[y] - 1] > x && inv[v[y] - 1] < y) add(v[y] - 1, 1);
				if(v[y] < n - 1 && inv[v[y] + 1] > x && inv[v[y] + 1] < y) add(v[y], -1);
			}
			inv[v[x]] = y;
			inv[v[y]] = x;
			swap(v[x], v[y]);
			deb();
		}
	}
}