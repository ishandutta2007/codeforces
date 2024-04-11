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

int main() {
	int a[6], i;
	for(i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	printf("%d\n", (a[0] + a[1] + a[5]) * (a[0] + a[1] + a[5]) - a[1] * a[1] - a[3] * a[3] - a[5] * a[5]);
}