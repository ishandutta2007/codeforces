#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<=n;i++)

const int Q = 600000;

bitset<505>b1[505][505], b2[505][505]; bool ans[Q + 5];
struct query{int x1, y1, x2, y2, id;}qry[Q + 5];
char s[505][505]; int n, m, q;

void solve(int l, int r, int k) {
	if( l > r || !k ) return ;
	int mid = (l + r) >> 1;
	
	for(int i=m;i>=1;i--) {
		if( s[mid][i] != '#' )
			b1[mid][i] = b1[mid][i + 1], b1[mid][i][i] = 1;
		else b1[mid][i] = 0;
	}
	for(int i=mid-1;i>=l;i--) {
		for(int j=m;j>=1;j--) {
			if( s[i][j] != '#' )
				b1[i][j] = b1[i][j + 1] | b1[i + 1][j];
			else b1[i][j] = 0;
		}
	}
	
	for(int i=1;i<=m;i++) {
		if( s[mid][i] != '#' )
			b2[mid][i] = b2[mid][i - 1], b2[mid][i][i] = 1;
		else b2[mid][i] = 0;
	}
	for(int i=mid+1;i<=r;i++) {
		for(int j=1;j<=m;j++) {
			if( s[i][j] != '#' )
				b2[i][j] = b2[i][j - 1] | b2[i - 1][j];
			else b2[i][j] = 0;
		}
	}
	
	rep(i, 1, k) if( qry[i].x1 <= mid && mid <= qry[i].x2 )
		ans[qry[i].id] = (b1[qry[i].x1][qry[i].y1] & b2[qry[i].x2][qry[i].y2]).any();
	
	int p = 0;
	rep(i, 1, k) if( qry[i].x2 < mid ) swap(qry[i], qry[++p]);
	solve(l, mid - 1, p);
	
	p = 0;
	rep(i, 1, k) if( qry[i].x1 > mid ) swap(qry[i], qry[++p]);
	solve(mid + 1, r, p);
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	scanf("%d", &q);
	rep(i, 1, q) {
		scanf("%d%d%d%d", &qry[i].x1, &qry[i].y1, &qry[i].x2, &qry[i].y2);
		qry[i].id = i;
	}
	
	solve(1, n, q); rep(i, 1, q) puts(ans[i] ? "Yes" : "No");
}