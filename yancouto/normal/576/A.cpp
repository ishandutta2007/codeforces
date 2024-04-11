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

int b[1003], a[1003];
int main() {
	int i, j = 0, k = 0;
	int n;
	scanf("%d", &n);
	for(i = 2; i <= n; i++) {
		b[i] = i;
	}
	for(i = 2; i <= n; i++) {
		if(b[i] == 1) continue;
		a[j++] = i;
		for(int k =  2*i; k <= n; k += i)
			b[k] /= b[i];
	}
	printf("%d\n", j);
	for(i = 0; i < j; i++)
		printf("%d ", a[i]);
	putchar('\n');
}