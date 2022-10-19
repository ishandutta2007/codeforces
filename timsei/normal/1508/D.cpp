//check 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;


int n, A[N], isc[N];

vector <int> cyc;

struct Point {
	int x, y, id;
	void input() {
		scanf("%d%d", &x, &y);
	}
	double norm() {
		return sqrt(1LL * x * x + 1LL * y * y);
	}
	friend Point operator - (Point a, Point b) {
		return (Point){a.x - b.x, a.y - b.y};
	}
	friend bool operator < (Point a, Point b) {
		return a.y < b.y;
	}
}P[N];

vector < Point > ans;

void dfs(int x) {
	if(A[x] == x) return;
	ans.push_back((Point){x, A[x]});
	swap(A[x], A[A[x]]);
	dfs(x);
}

void solve(int x, int lb) {
	if(isc[x]) return;
	isc[x] = lb;
	solve(A[x], lb);
}

double get(Point x) {
	double it = x.x / x.norm();
	if(x.y < 0 || (x.x < 0 && x.y == 0)) it = -2 - it; 
	return it;
} 

bool cmp(Point a, Point b) {
	return get(a - P[1]) < get(b - P[1]);
}

int getf(int x) {
	return (isc[x] == x) ? x : isc[x] = getf(isc[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		P[i].input(); scanf("%d", &A[i]); P[i].id = i;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(A[i] == i) continue;
		if(!isc[i]) {
			solve(i, i);
			++ cnt;
		}
	}
	if(!cnt) {
		puts("0");
		return 0;
	}
	
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(A[i] != i) P[++ tot] = P[i];
	sort(P + 1, P + tot + 1);
	sort(P + 2, P + tot + 1, cmp);
	
	for(int i = 2; i < tot;++ i) {
		if(getf(P[i].id) != getf(P[i + 1].id)) {
			ans.push_back((Point) {P[i].id, P[i + 1].id});
			isc[getf(P[i].id)] = getf(P[i + 1].id);
			swap(A[P[i].id], A[P[i + 1].id]);
		}
	}
	
	cnt = 0;
	for(int i = 1; i <= n; ++ i) isc[i] = 0;
	for(int i = 1; i <= n; ++ i) {
		if(A[i] == i) continue;
		if(!isc[i]) {
			solve(i, i);
			++ cnt;
		}
	}
	if(cnt > 1) while(1);
	
	dfs(P[1].id);
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); ++ i) printf("%d %d\n", ans[i].x, ans[i].y)
;
puts("");
}