#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1001;

int n, deg[N];
vector<int> e[N];
queue<int> q;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	rep(i, 0, n) 
		if (deg[i] == 1)
			q.push(i);

	while (q.size() >= 2) {
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		cout << "? " << a + 1 << " " << b + 1 << endl;
		int lca;
		cin >> lca;
		lca--;
		if (lca == a || lca == b) {
			cout << "! " << lca + 1 << endl;
			return 0;
		}
		for (auto u : {a, b})
			for (auto v : e[u]) {
				if (--deg[v] == 1) {
					q.push(v);
				}
			}
	}
	cout << "! " << q.front() + 1 << endl;
	return 0;
}