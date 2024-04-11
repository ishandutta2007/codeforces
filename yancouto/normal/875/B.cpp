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
#	define debug(args...) ((void) 0)
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

int a[512345];

int main() {
	int i, j;
	rd(n);
	printf("1");
	int lst = n;
	for(i = 0; i < n; i++) {
		int x;
		rd(x);
		a[x] = 1;
		while(lst >= 1 && a[lst]) lst--;
		printf(" %d", 1 + (i + 1) - (n - lst));
	}
	putchar('\n');
}