#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int Segment_Size = N * 4;

int L[Segment_Size], R[Segment_Size], M1[Segment_Size], M2[Segment_Size], A[N], n;

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

void up(int no) {
	M1[no] = max(M1[lc], M1[rc]);
	M2[no] = max(M2[lc], M2[rc]);
}

void build(int no, int l, int r) {
	L[no] = l, R[no] = r;
	if(L[no] == R[no]) {
		M1[no] = max(A[l], A[l + 1]);
		M2[no] = min(A[l], max(A[l - 1], A[l + 1]));
		return;
		
	}
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(no);
}

#define pii pair <int, int> 
#define mp make_pair
#define fi first
#define se second

pii Max(pii a, pii b) {
	return mp(max(a.fi, b.fi), max(a.se, b.se));
}

pii Q(int no, int l, int r) {
//	cerr << l <<' ' << r << endl;
	if(L[no] == l && R[no] == r) {
		return mp(M1[no], M2[no]);
	}
	getmid;
	if(l > mid) return Q(rc, l, r);
	else if(r <= mid) return Q(lc, l, r);
	else return Max(Q(lc, l, mid), Q(rc, mid + 1, r));
}

int main() {
	cin >>  n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	build(1, 1, n);
	for(int i = 0; i < n; ++ i) {
		if(i == n - 1) {
			int ans = -1;
			for(int j = 1; j <= n; ++ j)
			ans = max(ans, A[j]);
			cout << ans << endl;
			continue;
		}
		int Left = n - i;
		if(Left % 2 == 0) {
			printf("%d ", Q(1, (n - i + 1) / 2, (n + i + 1) / 2).fi);
		} else {
			printf("%d ", Q(1, (n - i + 1) / 2, (n + i + 1) / 2).se);
		}
	}
}