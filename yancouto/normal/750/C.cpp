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

void imp() {
	puts("Impossible");
	exit(0);
}

const int N = 212345;
int c[N], d[N];

int main() {
	int i, j;
	rd(n);
	int cur = 0;
	int mx_div2 = INT_MIN;
	for(i = 0; i < n; i++) {
		rd(c[i]); rd(d[i]);
		if(d[i] == 2) mx_div2 = max(mx_div2, cur);
		cur += c[i];
	}
	if(mx_div2 == INT_MIN) { puts("Infinity"); return 0; }
	cur = 0;
	for(i = 0; i < n; i++) {
		if(d[i] == 2 && (cur - mx_div2 + 1899) > 1899) imp();
		if(d[i] == 1 && (cur - mx_div2 + 1899) <= 1899) imp();
		cur += c[i];
	}
	printf("%d\n", cur - mx_div2 + 1899);
}