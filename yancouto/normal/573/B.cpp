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

int a[100009], k[100009], k2[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k[0] = 1;
	for(i = 1; i < n; i++)
		k[i] = min(k[i - 1] + 1, a[i]);
	k[n - 1] = 1;
	for(i = n - 2; i >= 0; i--)
		k[i] = min(k[i], k[i + 1] + 1);
	printf("%d\n", *max_element(k, k + n));
}