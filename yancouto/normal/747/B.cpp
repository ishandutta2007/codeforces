#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

int oc[256];
char s[11234];

int main() {
	int i, j;
	rd(n);
	scanf("%s", s);
	for(i = 0; i < n; i++) oc[s[i]]++;
	int mx = max(max(oc['A'], oc['T']), max(oc['C'], oc['G']));
	int A, T, C, G;
	A = mx - oc['A'];
	T = mx - oc['T'];
	C = mx - oc['C'];
	G = mx - oc['G'];
	int q = oc['?'] - A - T - C - G;
	if(q < 0 || (q % 4)) { puts("==="); return 0; }
	A += q / 4;
	T += q / 4;
	C += q / 4;
	G += q / 4;
	for(i = 0; i < n; i++) {
		if(s[i] != '?') putchar(s[i]);
		else if(A) putchar('A'), A--;
		else if(T) putchar('T'), T--;
		else if(C) putchar('C'), C--;
		else if(G) putchar('G'), G--;
		else assert(0);
	}
	putchar('\n');
}