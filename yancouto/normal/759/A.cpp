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
int b[212345], p[212345], seen[212345];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(p[i]), p[i]--;
	for(i = 0; i < n; i++) rd(b[i]);
	int tot = 0;
	if(!(accumulate(b, b + n, 0) & 1)) tot++;
	int cyc = 0;
	for(i = 0; i < n; i++) {
		if(seen[i]) continue;
		cyc++;
		j = i;
		while(!seen[j]) {
			seen[j] = true;
			j = p[j];
		}
	}
	if(cyc > 1) tot += cyc;
	printf("%d\n", tot);
}