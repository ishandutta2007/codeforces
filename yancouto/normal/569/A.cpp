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
	int t, s, q;
	scanf("%d %d %d", &t, &s, &q);
	int ct = 1;
	while(true) {
		int inter = s * q;
		if(inter >= t) break;
		ct++;
		s = inter;
	}
	printf("%d\n", ct);
	return 0;
}