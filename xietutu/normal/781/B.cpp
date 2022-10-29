#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
#define F first
#define S second
#define VI vector<int>
#define PB push_back
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned int ui;
queue<int> Q;
int n, op[MAXN];
bool vis[MAXN][2];
string s[MAXN][2];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string l, r;
		cin >> l >> r;
		for (int j = 0; j < 2; ++j) s[i][0] += l[j], s[i][1] += l[j];
		s[i][0] += l[2]; s[i][1] += r[0];
	}
	memset(vis, true, sizeof vis);
	memset(op, 255, sizeof op);
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j)
			if (i != j && s[i][0] == s[j][0]) {
				flag = false; break;
			}
		if (!flag) vis[i][0] = false, op[i] = 1, Q.push(i);
	}
	
	while (Q.size()) {
		int id = Q.front(); Q.pop();
		string now = s[id][op[id]];
		for (int i = 1; i <= n; ++i) {
			if (i == id) continue;
			for (int j = 0; j < 2; ++j)
				if (s[i][j] == now) {
					vis[i][j] = false;
					if (op[i] == -1) {
						Q.push(i);
						op[i] = j ^ 1;
					}
				}
		}
		
	}
	
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		if (!vis[i][0] && !vis[i][1]) flag = false;
	if (flag) {	
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i)
			if (op[i] == -1) cout << s[i][0] << endl;
			else cout << s[i][op[i]] << endl;
	}
	else puts("NO");
}