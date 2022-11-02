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

char f[100004][2][53];
char aux[55];
int p[100009], inv[100009];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s %s", f[i][0], f[i][1]);
		if(strcmp(f[i][0], f[i][1]) > 0)
			for(j = 0; j < 51; j++)
				swap(f[i][0][j], f[i][1][j]);
	}
	for(i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		inv[i] = --p[i];
	}
	strcpy(aux, f[inv[0]][0]);
	for(i = 1; i < n; i++) {
		if(strcmp(f[inv[i]][0], aux) > 0) { strcpy(aux, f[inv[i]][0]); continue; }
		if(strcmp(f[inv[i]][1], aux) > 0) { strcpy(aux, f[inv[i]][1]); continue; }
		puts("NO");
		return 0;
	}
	puts("YES");
}