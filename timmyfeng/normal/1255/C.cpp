#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000 + 1];
int q[100000 - 2][3];
int ord[100000 - 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			int a;
			cin >> a;
			q[i][j] = a;
			adj[a].push_back(i);
		}
	}
	
	int p1 = 1;
	for ( ; p1 <= n; ++p1) {
		if (adj[p1].size() == 1) {
			ord[0] = adj[p1][0];
			break;
		}
	}
	int p2, p3;
	for (auto i : q[ord[0]]) {
		if (adj[i].size() == 2) {
			p2 = i;
		} else if (adj[i].size() == 3) {
			p3 = i;
		}
	}
	cout << p1 << ' ';
	for (int k = 1; k < n - 2; ++k) {
		for (auto i : adj[p2]) {
			if (find(q[i], q[i] + 3, p1) == q[i] + 3 && 
					find(q[i], q[i] + 3, p3) != q[i] + 3) {
				ord[k] = i;
				break;
			}
		}
		p1 = p2;
		p2 = p3;
		for (auto i : q[ord[k]]) {
			if (i != p1 && i != p2) {
				p3 = i;
			}
		}
		cout << p1 << ' ';
	}
	cout << p2 << ' ' << p3 << '\n';
}