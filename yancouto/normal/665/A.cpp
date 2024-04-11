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

int main() {
	int a, ta, b, tb, h, m, t, i;
	scanf("%d %d", &a, &ta);
	scanf("%d %d", &b, &tb);
	scanf("%d %*c %d", &h, &m);
	t = 60 * h + m;
	int tot = 0;
	for(i = 5 * 60; i < 24 * 60; i += b)
		if(i + tb > t && i < t + ta)
			tot++;
	printf("%d\n", tot);
}