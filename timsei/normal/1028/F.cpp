#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

struct Point {
	int x, y;
	
	friend bool operator < (Point a, Point b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
	}
	
	friend bool operator == (Point a, Point b) {
		return (a.x == b.x) && (a.y == b.y);
	}
	
	friend Point operator + (Point a, Point b) {
		Point cxt;
		cxt.x = a.x + b.x;
		cxt.y = a.y + b.y;
		int g = gcd(cxt.x, cxt.y);
		cxt.x /= g;
		cxt.y /= g;
		return cxt;
	}
};

map <int, set < Point > > S;
map <Point, int> cxt;

int n, ty, x, y, tot;

main(void) {
	cin.sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> ty >> x >> y;
		Point lsk = (Point){x, y};
		if(ty == 1) {
			++ tot;
			int now = x * x + y * y;
			for(auto V : S[now]) {
				cxt[V + lsk] += 2;
			}
			S[now].insert(lsk);
			lsk = lsk + (Point) {0, 0};
			++ cxt[lsk];
		}
		else if(ty == 2) {
			-- tot;
			int now = x * x + y * y;
			S[now].erase(lsk);
			for(auto V : S[now]) {
				cxt[V + lsk] -= 2;
			}
			lsk = lsk + (Point) {0, 0};
			-- cxt[lsk];
		}
		else {
			lsk = lsk + (Point){0, 0};
			cout << tot - cxt[lsk] << endl;
		}
	}
}