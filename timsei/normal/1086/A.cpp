#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

struct P {
	int x, y;
	void input() {
		cin >> x >> y;
	}
	void print() {
		cout << x <<" " << y << endl;
	}
}A[4];

int dis(P a, P b) {
	return abs(a.x - b.x) + abs(a.y - b.y) - 1;
}

vector < pair <int, int> > Vec;

int calc(int x, int y) {
	return x * 100 + y;
}

bool vis[1005][1005];

void go(P a, P b) {
	vis[a.x][a.y] = 1;
	if(a.x == b.x && a.y == b.y) return;
	if(a.x != b.x) {
		if(a.x < b.x) ++ a.x;
		else -- a.x;
		go(a, b);
	}
	else {
		if(a.y < b.y) ++ a.y;
		else -- a.y;
		go(a, b);
	}
}

void solve(P x) {
	go(A[1], x);
	go(A[2], x);
	go(A[3], x);
}

int main() {
	for(int i = 1; i <= 3; ++ i) A[i].input();
	int ans = 1e9;
	for(int i = 0; i <= 1000; ++ i) {
		for(int j = 0; j <= 1000; ++ j) {
			P now = (P){i, j};
			ans = min(ans, dis(A[1], now) + dis(A[2], now) + dis(A[3], now));
		}
	}
	bool ok = 1;
	for(int i = 0; ok && i <= 1000; ++ i) {
		for(int j = 0; ok && j <= 1000 ; ++ j) {
			P now = (P){i, j};
			int res = dis(A[1], now) + dis(A[2], now) + dis(A[3], now);
			if(res == ans) {
				solve(now);
				//cout << i <<" " << j << endl;
				ok = 0; break;
			}
		}
	}
	cout << ans + 4 << endl;
	for(int i = 0; i <= 1000; ++ i) {
		for(int j = 0; j <= 1000; ++ j) if(vis[i][j]) cout << i <<" " << j << endl;
	}
}