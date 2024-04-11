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
const int N = 1000009;
char s[N];
char st[N]; int sn;
char op[256];

int main() {
	int i;
	op[')'] = '(';
	op['}'] = '{';
	op[']'] = '[';
	op['>'] = '<';
	scanf("%s", s);
	int tot = 0;
	for(i = 0; s[i]; i++) {
		if(!op[s[i]]) { st[sn++] = s[i]; continue; }
		if(sn == 0) { puts("Impossible"); return 0; }
		tot += (op[s[i]] != st[--sn]);
	}
	if(sn) puts("Impossible");
	else printf("%d\n", tot);
}