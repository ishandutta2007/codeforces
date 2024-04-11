#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
const int Segment_Size = N * 4;

#define int long long

int L[Segment_Size], R[Segment_Size], MAX[Segment_Size], n, m, x, y, S[Segment_Size];

struct Point {
	int x1, y1, x2, y2;
	void input(void) {
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	}
}P[N];

vector <int> X, Y;

map <int, int> Mx, My;

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

void build(int no, int l, int r) {
	L[no] = l, R[no] = r;
	if(l == r) return;
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}

void up(int no) {
	MAX[no] = max(MAX[rc], MAX[lc]) + S[no];
}

void Add(int no, int l, int r, int x) {
	if(L[no] == l && R[no] == r) {
		S[no] += x;
		if(L[no] == R[no]) MAX[no] = S[no];
		else up(no);
		return;
	}
	getmid;
	if(l > mid) Add(rc, l, r, x);
	else if(r <= mid) Add(lc, l, r, x);
	else Add(lc, l, mid, x), Add(rc, mid + 1, r, x);
	up(no);
}

struct Opt{
	int l, r, who;
};

vector < Opt> G[N];

int query(int no, int x) {
	if(L[no] == R[no]) {
		return L[no];
	}
	if(MAX[lc] + S[no] == x) {
		return query(lc, x - S[no]);
	}
	return query(rc, x - S[no]);
}

int solve(void) {
	return Y[query(1, MAX[1]) - 1];
}

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) P[i].input(), X.push_back(P[i].x1), Y.push_back(P[i].y1), X.push_back(P[i].x2), Y.push_back(P[i].y2);
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for(int i = 0; i < (int)X.size(); ++ i) Mx[X[i]] = i + 1;
	for(int i = 0; i < (int) Y.size(); ++ i) My[Y[i]] = i + 1;
	for(int i = 1; i <= n; ++ i) {
		P[i].x1 = Mx[P[i].x1];
		P[i].y1 = My[P[i].y1];
		P[i].x2 = Mx[P[i].x2];
		P[i].y2 = My[P[i].y2];
		G[P[i].x1].push_back((Opt) {P[i].y1, P[i].y2, 1});
		G[P[i].x2 + 1].push_back((Opt) {P[i].y1, P[i].y2, -1});
	}
	build(1, 1, Y.size());
	for(int i = 1; i <= X.size(); ++ i){
		for(int j = 0; j < (int) G[i].size(); ++ j) Add(1, G[i][j].l, G[i][j].r, G[i][j].who);
		if(MAX[1] >= n - 1) {
			cout << X[i - 1] << " "  <<  solve() << endl;
			return 0;
		} 
	}
}