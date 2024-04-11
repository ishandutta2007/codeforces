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
char s[2009], u[2009];
int diff(char *a, char *b, int n) {
	int d = 0;
	for(int i = 0; i < n; i++)
		d += a[i] != b[i];
	return d;
}

int main() {
	int i;
	scanf("%s %s", s, u);
	int sn = strlen(s), su = strlen(u);
	if(sn >= su) {
		int mn = INT_MAX;
		for(i = 0; i + su - 1 < sn; i++)
			mn = min(mn, diff(s + i, u, su));
		for(i = -1; i + su - 1 >= 0; i--)
			mn = min(mn, -i + diff(s, u - i, su + i));
		for(i = sn - su + 1; i < sn; i++)
			mn = min(mn, i - sn + su + diff(s + i, u, su - (i - sn + su)));
		printf("%d\n", mn);
	} else {
		int mn = INT_MAX;
		for(i = 0; i + sn - 1 < su; i++)
			mn = min(mn, diff(u + i, s, sn));
		for(i = -1; i + sn - 1 >= 0; i--)
			mn = min(mn, -i + diff(u, s - i, sn + i));
		for(i = su - sn + 1; i < su; i++)
			mn = min(mn, i - su + sn + diff(s, u + i, sn - (i - su + sn)));
		printf("%d\n", mn + su - sn);
	}
}