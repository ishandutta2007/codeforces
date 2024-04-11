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

const int N = 212345;
int lim[N], ln;
int ovr[N], on;

int main() {
	int i, j;
	rd(n);
	int v, d, t;
	int tot = 0;
	for(i = 0; i < n; i++) {
		rd(t);
		if(t == 1 || t == 3) rd(d);
		if(t == 1) {
			v = d;
			while(ln && lim[ln - 1] < v) ln--, tot++;
		} else if(t == 2) {
			while(on && ovr[on - 1] == 0) on--, tot++;
		} else if(t == 3) {
			if(d < v) tot++;
			else lim[ln++] = d;
		} else if(t == 4)
			ovr[on++] = 1;
		else if(t == 5)
			lim[ln++] = 300;
		else if(t == 6)
			ovr[on++] = 0;
	}
	printf("%d\n", tot);
}