#include <bits/stdc++.h>

const int N = 500;

bool a[N + 5][N + 5], b[N + 5][N + 5], d[N + 5][N + 5];

bool f(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N) ? a[x][y] : false;
}

void dfs(int x, int y) {
	if( b[x][y] ) return ; b[x][y] = true;
	if( f(x - 1, y) ) dfs(x - 1, y);
	if( f(x + 1, y) ) dfs(x + 1, y);
	if( x & 1 ) {
		if( f(x - 1, y + 1) ) dfs(x - 1, y + 1);
	} else {
		if( f(x + 1, y - 1) ) dfs(x + 1, y - 1);
	}
}

struct node{int x, y;}; std::queue<node>que;
void try_add(int i, int j, bool k) {
	if( f(i, j) == k ) return ;
	int c = (f(i + 1, j) == k) + (f(i - 1, j) == k);
	if( i & 1 ) c += (f(i - 1, j + 1) == k); else c += (f(i + 1, j - 1) == k);
	if( c >= 2 ) que.push((node){i, j});
}
int main() {
	int n; scanf("%d", &n);
	for(int i=1,x,y;i<=n;i++)
		scanf("%d%d", &x, &y), a[x][y] = true;
	
	int ans = 0;
	for(int i=-1;i<=N;i++) for(int j=-1;j<=N;j++) {
		ans += (f(i, j) != f(i + 1, j));
		if( i & 1 ) ans += (f(i, j) != f(i - 1, j + 1));
	}
	
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
		if( !f(i, j) && f(i + 1, j) && f(i - 1, j)  ) {
			if( i & 1 ) {
				if( f(i - 1, j + 1) ) d[i][j] = true;
			} else {
				if( f(i + 1, j - 1) ) d[i][j] = true;
			}
		}
	}
	
	for(int i=-1;i<N;i++) for(int j=-1;j<=N;j++) try_add(i, j, true);
	while( !que.empty() ) {
		node x = que.front(); que.pop();
		a[x.x][x.y] = true, try_add(x.x - 1, x.y, true), try_add(x.x + 1, x.y, true);
		if( x.x & 1 ) try_add(x.x - 1, x.y + 1, true); else try_add(x.x + 1, x.y - 1, true);
	}
	
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if( d[i][j] ) {
		if( i & 1 ) {
			if( !f(i + 2, j) && !f(i - 2, j) && !f(i, j + 1)
				&& !f(i - 2, j + 1) && !f(i, j - 1) && !f(i + 2, j - 1) )
					ans -= 2;
		}
		else {
			if( !f(i + 2, j) && !f(i - 2, j) && !f(i, j - 1)
				&& !f(i + 2, j - 1) && !f(i, j + 1) && !f(i - 2, j + 1) )
					ans -= 2;
		}
	}
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if( a[i][j] && !b[i][j] )
		ans -= 2, dfs(i, j);
	
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) try_add(i, j, false);
	while( !que.empty() ) {
		node x = que.front(); que.pop();
		a[x.x][x.y] = false, try_add(x.x - 1, x.y, false), try_add(x.x + 1, x.y, false);
		if( x.x & 1 ) try_add(x.x - 1, x.y + 1, false); else try_add(x.x + 1, x.y - 1, false);
	}
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if( a[i][j] ) {
		puts("SICK"); return 0;
	}
	
	printf("RECOVERED\n%d\n", ans);
}