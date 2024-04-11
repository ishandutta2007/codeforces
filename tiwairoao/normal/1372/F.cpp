#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;

struct type{int x, f;};

type query(int l, int r) {
	printf("? %d %d\n", l, r), fflush(stdout);
	type ret; scanf("%d%d", &ret.x, &ret.f);
	return ret;
}

int a[N + 5];
void cover(int l, int r, int c) {
	for(int i=l;i<=r;i++) a[i] = c;
}

map<int, int>vis, tag;
void solve(int l, int r, type t) {
	if( r - l + 1 == t.f ) {
		cover(l, r, t.x), vis[t.x] = true;
		if( tag[t.x] ) tag[t.x] -= t.f;
	} else if( vis[t.x] ) {
		cover(l, l + t.f - 1, t.x);
		if( l + t.f <= r ) solve(l + t.f, r, query(l + t.f, r));
	} else if( tag[t.x] ) {
		cover(r - t.f + 1, r, t.x);
		if( l <= r - t.f ) solve(l, r - t.f, query(l, r - t.f));
		tag[t.x] -= t.f;
	} else {
		tag[t.x] = t.f;
		for(int i=l;i<=r;i+=t.f) {
			int j = min(r, i + t.f - 1);
			
			type p = query(i, j);
			if( p.x == t.x ) {
				int lk = j - p.f + 1, rk = j + (t.f - p.f);
				cover(lk, rk, p.x);
				if( i <= lk - 1 ) solve(i, lk - 1, query(i, lk - 1));
				if( rk + 1 <= r ) solve(rk + 1, r, query(rk + 1, r));
				break;
			} else {
				solve(i, j, p);
				if( tag[t.x] != t.f ) {
					cover(j + 1, j + tag[t.x], t.x);
					if( j + tag[t.x] + 1 <= r ) solve(j + tag[t.x] + 1, r, query(j + tag[t.x] + 1, r));
					break;
				}
			}
		}
		vis[t.x] = true;
	}
}

int main() {
	int n; scanf("%d", &n), solve(1, n, query(1, n));
	
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	fflush(stdout);
}