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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const int MAX = 200009;
int n, m, p;
int f1[MAX<<1], f2[MAX<<1];
int a[MAX], b[MAX];
int ok;

void add(int x) {
	if(f1[x] == f2[x]) ok--;
	f1[x]++;
	if(f1[x] == f2[x]) ok++;
}

void rem(int x) {
	if(f1[x] == f2[x]) ok--;
	f1[x]--;
	if(f1[x] == f2[x]) ok++;
}

int qs[MAX];
int main() {
	int i, j, x;
	scanf("%d %d %d", &n, &m, &p);
	map<int, int> ma;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(ma.count(x))
			a[i] = ma[x];
		else {
			int aux = ma.size();
			a[i] = ma[x] = aux;
		}
	}
	for(i = 0; i < m; i++) {
		scanf("%d", &x);
		if(ma.count(x))
			b[i] = ma[x];
		else {
			int aux = ma.size();
			b[i] = ma[x] = aux;
		}
		f2[b[i]]++;
	}
	ok = 0;
	int base_ok = 0;
	for(i = 0; i < ma.size(); i++)
		if(!f2[i])
			base_ok++;
	if(n < m) { puts("0"); return 0; }
	// talvez diferente se p == 1
	int num = 0;
	int qi = 0;
	for(i = 0; i < p; i++) {
		ok = base_ok;
		for(j = 0; (i + j*p) < n && j < m; j++)
			add(a[i + j*p]);
		if(ok == ma.size()) {
			qs[qi++] = i;
			num++;
		}
		for(; (i + j*p) < n; j++) {
			rem(a[i + (j-m)*p]);
			add(a[i + j*p]);
			if(ok == ma.size()) {
				qs[qi++] =  i + (j-m+1)*p;
				num++;
			}
		}
		if(!j) continue;
		for(j--; j >= 0; j--)
			f1[a[i + j*p]] = 0;
	}
	sort(qs, qs + qi);
	printf("%d\n", num);
	for(i = 0; i < qi; i++)
		printf("%d ", qs[i] + 1);
	putchar('\n');
	return 0;
}