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

char s[300009];
int main() {
	int i;
	scanf("%s", s);
	ll tot = 0;
	for(i = 0; s[i] && s[i + 1]; i++) {
		if((((s[i] - '0') * 10 + s[i + 1] - '0') % 4) == 0)
			tot += (i + 1);
		if(((s[i] - '0') % 4) == 0)
			tot++;
	}
	if(((s[i] - '0') % 4) == 0) tot++;
	printf("%I64d\n", tot);
}