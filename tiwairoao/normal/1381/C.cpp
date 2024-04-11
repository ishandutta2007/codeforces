#include <bits/stdc++.h>

#define pr std::make_pair
#define fi first
#define se second

typedef std::pair<int, int> pii;

const int N = 100000;

std::vector<int>v[N + 5];

int b[N + 5], c[N + 5];
void solve() {
	int n, x, y; scanf("%d%d%d", &n, &x, &y), y -= x;
	for(int i=1;i<=n+1;i++) v[i].clear();
	for(int i=1;i<=n;i++) scanf("%d", &b[i]), v[b[i]].push_back(i);
	for(int i=1;i<=n+1;i++) if( v[i].empty() ) {
		for(int j=1;j<=n;j++) c[j] = i;
		break;
	}

	std::priority_queue<pii>que;
	for(int i=1;i<=n+1;i++) if( !v[i].empty() )
		que.push(pr(v[i].size(), i));
		
	int m = n - x;
	while( x ) {
		pii p = que.top(); que.pop(), p.fi--;
		c[v[p.se].back()] = p.se, v[p.se].pop_back(), x--;
		if( p.fi ) que.push(p);
	}
	
	std::stack<pii>ans;
	if( !que.empty() ) {
		if( 2 * que.top().fi <= m ) {
			if( m & 1 ) {
				pii p = que.top(); que.pop(), p.fi--;
				pii q = que.top(); que.pop(), q.fi--;
				pii r = que.top(); que.pop(), r.fi--;
				ans.push(pr(v[p.se].back(), q.se)), v[p.se].pop_back();
				ans.push(pr(v[q.se].back(), r.se)), v[q.se].pop_back();
				ans.push(pr(v[r.se].back(), p.se)), v[r.se].pop_back();
				if( p.fi ) que.push(p);
				if( q.fi ) que.push(q);
				if( r.fi ) que.push(r);
			}
		}
		while( que.size() > 1 ) {
			pii p = que.top(); que.pop(), p.fi--;
			pii q = que.top(); que.pop(), q.fi--;
			ans.push(pr(v[p.se].back(), q.se)), v[p.se].pop_back();
			ans.push(pr(v[q.se].back(), p.se)), v[q.se].pop_back();
			if( p.fi ) que.push(p);
			if( q.fi ) que.push(q);
		}
	}
	
	while( y-- ) {
		if( ans.empty() ) {puts("NO"); return ;}
		else {
			pii p = ans.top(); ans.pop();
			c[p.fi] = p.se;
		}
	}
	puts("YES"); for(int i=1;i<=n;i++) printf("%d ", c[i]); puts("");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}