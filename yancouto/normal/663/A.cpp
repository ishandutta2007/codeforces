#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

char s[112345];
int main() {
	int i, j, n;
	s[0] = '+'; s[1] = ' ';
	fgets(s + 2, (sizeof s) - 2, stdin);
	int sz = strlen(s) - 1;
	for(i = sz - 2; isdigit(s[i]); i--);
	n = atoi(s + i + 1);
	int cp = 0, cm = 0;
	for(i = 0; i < sz; i++)
		if(s[i] == '+') cp++;
		else if(s[i] == '-') cm++;
	int mn = cp - n * cm, mx = n * cp - cm;
	if(n < mn || n > mx) { puts("Impossible"); return 0; }
	puts("Possible");
	for(i = 0; i < sz; i++)
		if(s[i] == '+') {
			if(i) printf(" + ");
			int v = n;
			while(mx > n && v > 1) v--, mx--;
			printf("%d", v);
		} else if(s[i] == '-') {
			printf(" - ");
			int v = 1;
			while(mx > n && v < n) v++, mx--;
			printf("%d", v);
		}
	printf(" = %d\n", n);
}