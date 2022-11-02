#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int MAXM = 5000;
const int MAXN = 100000;

int n, m, k;
ll a[MAXN + 5], h[MAXN + 5], p;
queue<pii>que[MAXM + 5];
bool check(ll x) {
	for(int i=1;i<=m;i++) {
		while( !que[i].empty() )
			que[i].pop();
	}
	
	for(int i=1;i<=n;i++) {
		ll s = x / a[i] + 1;
		if( s <= m ) que[s].push(mp(i, 0));
	}
	
	for(int i=1,c=0;i<=m;i++,c+=k) {
		while( !que[i].empty() ) {
			if( c ) c--; else return false;
			
			pii f = que[i].front(); que[i].pop(); f.se++;
			ll s = (f.se*p + x) / a[f.fi] + 1;
			if( s <= m ) que[s].push(f);
		}
	}
	
	ll s = 0;
	for(int i=1;i<=n;i++)
		s += (max(a[i]*m + h[i] - x, 0LL) + p - 1) / p;
	return s <= m*k;
}

int main() {
	scanf("%d%d%d%lld", &n, &m, &k, &p);
	for(int i=1;i<=n;i++) scanf("%lld%lld", &h[i], &a[i]);
	
	ll le = 0, ri = 0;
	for(int i=1;i<=n;i++)
		ri = max(ri, h[i] + m*a[i]);
	
	while( le < ri ) {
		ll mid = (le + ri) >> 1;
		if( check(mid) ) ri = mid;
		else le = mid + 1;
	}
	printf("%lld\n", ri);
}

/*
max(0, hi - u1*p)

max(ai, hi + ai - u1*p)

max(0, ai - u2*p, hi + ai - (u1 + u2)*p)

max(ai, 2*ai - u2*p, hi + 2*ai - (u1 + u2)*p) <= mid

ai <= mid, 2*ai - u2*p <= mid, hi + 2*ai

y*ai - o*p >= x + 1

y >= (x + 1 + o*p) / a
*/