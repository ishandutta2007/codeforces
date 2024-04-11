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

char s[1000];
int c[256];
int main() {
	int i, n;
	scanf("%d", &n);
	scanf("%s", s);
	for(i = 0; i < n; i++)
		c[s[i]]++;
	int has = !!c['R'] + !!c['G'] + !!c['B'];
	if(has == 3) { puts("BGR"); return 0; }
	if(has == 1) { printf("%c\n", s[0]); return 0; }
	if((c['R'] > 1) + (c['G'] > 1) + (c['B'] > 1) == 2) { puts("BGR"); return 0; }
	if((c['R'] == 1) + (c['G'] == 1) + (c['B'] == 1) == 2) {
		if(!c['R']) puts("R");
		else if(!c['G']) puts("G");
		else if(!c['B']) puts("B");
		return 0;
	}
	if(c['R'] > 1) puts("BG");
	else if(c['G'] > 1) puts("BR");
	else puts("GR");
}