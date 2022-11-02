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
const int N = 112345;

int p10[20], tr[N * 19][2], ct[N * 19], en;

int main() {
	int i; ll x; char op;
	rd(n);
	p10[0] = 1;
	for(i = 0; i < n; i++) {
		scanf(" %c %lld", &op, &x);
		int v = 0;
		for(int j = 0; j <= 18; j++, x /= 10) {
			if(!tr[v][x % 2]) tr[v][x % 2] = ++en;
			v = tr[v][x % 2];
		}
		if(op == '+') ct[v]++;
		else if(op == '-') ct[v]--;
		else printf("%d\n", ct[v]);
	}
}