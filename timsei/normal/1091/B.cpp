#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

struct NODE {
	int x, y;
	friend bool operator < (NODE a, NODE b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
	}
	void input() {
		scanf("%d%d", &x, &y);
	}
}A[N], B[N];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++ i) A[i].input();
	for(int i = 1; i <= n; ++ i) B[i].input();
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	cout << A[1].x + B[n].x << " " << A[1].y + B[n].y
 << endl;}