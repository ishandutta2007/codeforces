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

char s[10009], s2[10009];
int main() {
	int i, l, r, k;
	scanf("%s", s);
	for_tests(m, mm) {
		scanf("%d %d %d", &l, &r, &k); l--; r--;
		int sz = r - l + 1;
		k %= sz;
		for(i = l; i <= r; i++)
			s2[i] = s[l + (sz - k + (i - l)) % sz];
		for(i = l; i <= r; i++)
			s[i] = s2[i];
	}
	puts(s);
}