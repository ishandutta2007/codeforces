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

int bit[100009];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
inline int get(int i, int j) { return get(j) - get(i - 1); }
void add(int i, int x) {
	for(i += 2; i < 100009; i += (i & -i))
		bit[i] += x;
}
int n;
int lef, rig;
bool flip;
int nr(int i) { return lef + i; }
int fl(int i) { return rig - i; }
int co(int i) { return flip? fl(i) : nr(i); }

void deb() {
	return;
	printf("(%d, %d)\n", lef, rig);
	for(int i = lef; i <= rig; i++)
		printf("%d ", get(i, i));
	putchar('\n');
}

int main() {
	int i, j, q, n, op, l, r;
	scanf("%d %d", &n, &q);
	for(i = 0; i < n; i++)
		add(i, 1);
	lef = 0; rig = n - 1;
	flip = false;
	for(j = 0; j < q; j++) {
		scanf("%d %d", &op, &l);
		if(op == 2) {
			scanf("%d", &r);
			if(!flip) printf("%d\n", get(nr(l), nr(r - 1)));
			else printf("%d\n", get(fl(r - 1), fl(l)));
			deb();
			continue;
		}
		if(l > (rig - lef + 1) / 2) {
			flip = !flip;
			l = (rig - lef + 1) - l;
		}
		for(i = l; i < 2 * l; i++) {
			int g = l - 1 - (i - l); 
			add(co(i), get(co(g), co(g)));
		}
		if(flip) rig -= l;
		else lef += l;
		deb();
	}
}