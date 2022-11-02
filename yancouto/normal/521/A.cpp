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

char str[100009];
int f[256];
char ch[4] = {'A','C','T','G'};
int main() {
	int i, n;
	for(i = 0; i < 4; i++)
		f[ch[i]] = i;
	scanf("%d %s", &n, str);
	int fr[4] = {0, 0, 0, 0};
	for(i = 0; i < n; i++)
		fr[f[str[i]]]++;
	int mx = 0;
	for(i = 0; i < 4; i++)
		mx = max(mx, fr[i]);
	ull mi = 0;
	for(i = 0; i < 4; i++)
		if(mx == fr[i])
			mi++;
	ull x = 1;
	for(i = 0; i < n; i++)
		x = mod(x * mi);
	printf("%I64u\n", x);
}