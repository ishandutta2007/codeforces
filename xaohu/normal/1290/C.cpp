#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 7e5 + 2020;

int n, k;
string s;
vector<int> v[N];
ll sz[N][2], res;
int p[N], col[N];

int find(int x) {
	if (p[x] == x)
		return x;
	int fa = find(p[x]);
	col[x] ^= col[p[x]];
	return p[x] = fa;
}

int main() { 
	cin >> n >> k >> s;
	rep(i, 0, k) {
		int m;
		cin >> m;
		rep(j, 0, m) {
			int x;
			cin >> x;
			x--;
			v[x].push_back(i);
		}
		sz[i][0] = 1;
		p[i] = i;
	}

	rep(i, 0, n)
		while (v[i].size() < 2) {
			sz[k][0] = 1e9;
			p[k] = k;
			v[i].push_back(k++);
		}

	rep(i, 0, n) {
		int a = find(v[i][0]);
		int b = find(v[i][1]);
		if (a != b) {
			res -= min(sz[a][0], sz[a][1]);
			res -= min(sz[b][0], sz[b][1]);

			if (s[i] == '0') 
				col[a] = col[v[i][0]] ^ col[v[i][1]] ^ 1;
			else 
				col[a] = col[v[i][0]] ^ col[v[i][1]];
			
			if (col[a]) {
				swap(sz[a][0], sz[a][1]);
			}

			p[a] = b;
			sz[b][0] += sz[a][0];
			sz[b][1] += sz[a][1];
			res += min(sz[b][0], sz[b][1]);
		}
		cout << res << "\n";
	}
	return 0;
}