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
const int N = 112345;
int a[N], b[N];

int main() {
	int i, j;
	int k1, k2;
	rd(n); rd(k1); rd(k2);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 0; i < n; i++) rd(b[i]);
	priority_queue<int> pq;
	for(i = 0; i < n; i++)
		pq.push(abs(a[i] - b[i]));
	for(i = 0; i < k1 + k2; i++) {
		int x = pq.top(); pq.pop();
		if(x == 0) x = 1;
		else x--;
		pq.push(x);
	}
	ll ans = 0;
	while(!pq.empty()) {
		ll x = pq.top(); pq.pop();
		ans += x * x;
	}
	printf("%lld\n", ans);
}