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

int a[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		while(!(a[i] & 1)) a[i] >>= 1;
		while(!(a[i] % 3)) a[i] /= 3;
	}
	for(i = 1; i < n; i++)
		if(a[i] != a[i-1])
			break;
	if(i < n) puts("No");
	else puts("Yes");
}