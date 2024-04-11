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
const int N = 212345, M = 312;

int a[M], b[M], t[N];
ll d1[N], d2[N];

queue<ll> q;
deque<ll> dq;

inline void clear() {
	while(!q.empty()) q.pop();
	dq.clear();
}

inline void enqueue(ll x) {
	q.push(x);
	while(!dq.empty() && x < dq.back()) dq.pop_back();
	dq.push_back(x);
}

inline void dequeue() {
	if(dq.front() == q.front()) dq.pop_front();
	q.pop();
}

inline ll query() {
	return dq.front();
}



int main() {
	int i, j, n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for(i = 0; i < m; i++)
		scanf("%d %d %d", &a[i], &b[i], &t[i]), a[i]--;
	for(j = m - 1; j >= 0; j--) {
		for(i = 0; i < n; i++)
			d2[i] = d1[i] + abs(i - a[j]);
		if(j == 0) break;
		//build(1, 0, n - 1);
		clear();
		enqueue(d2[0]);
		int s = 0, e = 0;
		for(i = 0; i < n; i++) {
			int l = max(0ll, i - ll(d) * ll(t[j] - t[j - 1]));
			int r = min(ll(n - 1), i + ll(d) * ll(t[j] - t[j - 1]));
			while(e < r) enqueue(d2[++e]);
			while(l > s) dequeue(), s++;
			d1[i] = query();
		}
	}
	printf("%lld\n", accumulate(b, b + m, 0ll) - (*min_element(d2, d2 + n)));
}