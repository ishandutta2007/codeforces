#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
const int N = 2005;
int n, st;
pii p[N];
bool vis[N];
string s;
bool on_right(pii a, pii b, pii c){
	int ux = b.fi - a.fi, vx = b.se - a.se;
	int uy = c.fi - b.fi, vy = c.se - b.se;
	return i64(ux) * vy < i64(vx) * uy;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	st = 1;
	for (int i = 2; i <= n; ++i) {
		if (p[i] < p[st]) {
			st = i;
		}
	}
	vis[st] = true;
	cin >> s;
	cout << st;
	for (char c : s) {
		int ed = 1;
		while (vis[ed]) ed++;
		for (int x = 1; x <= n; ++x) if (!vis[x]) {
			if (on_right(p[st], p[ed], p[x]) ^ (c == 'R')) {
				ed = x;
			}
		}
		cout << ' ' << ed;
		vis[ed] = true;
		st = ed;
	}
	for (int x = 1; x <= n; ++x) if (!vis[x]) cout << ' ' << x;
	cout << '\n';
}