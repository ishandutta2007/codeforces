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

struct minq {
	deque<ll> dq;
	queue<ll> q;
	int size() { return q.size(); }
	void enqueue(ll x) {
		while(!dq.empty() && dq.back() > x)
			dq.pop_back();
		dq.push_back(x);
		q.push(x);
	}
	void dequeue() {
		if(q.front() == dq.front())
			dq.pop_front();
		q.pop();
	}
	ll min() { return dq.front(); }
};

const int N = 112345;
ll a[N], dp[N], acc[N];

int main() {
	int i, j; ll c;
	rd(n); rd(c);
	for(i = 0; i < n; i++) rd(a[i]);
	acc[0] = a[0];
	for(i = 1; i < n; i++) acc[i] = acc[i - 1] + a[i];
	if(c == 1) { puts("0"); return 0; }
	minq dps, as;
	dp[n] = 0;
	dps.enqueue(dp[n] + acc[n - 1]);
	for(i = n - 1; i >= 0; i--) {
		dp[i] = dps.min() - (i? acc[i - 1] : 0);
		as.enqueue(a[i]);
		while(as.size() > c) as.dequeue();
		if(i + c <= n) {
			assert(as.size() == c);
			dp[i] = min(dp[i], acc[i + c - 1] - (i? acc[i - 1] : 0) - as.min() + dp[i + c]);
		}
		dps.enqueue(dp[i] + acc[i - 1]);
		while(dps.size() > c) dps.dequeue();
	}
	printf("%lld\n", dp[0]);
}