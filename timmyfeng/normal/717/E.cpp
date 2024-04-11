using namespace std;

#include <iostream>
#include <vector>

#define MAXN 200005

int N,a[MAXN],p[MAXN];
vector<int> g[MAXN],ans;


void dfs(int v) {
	// cout << "ENTERING " << v << endl;
	// cout << "ADDING " << " " << v << endl;
	ans.push_back(v);
	a[v] ^= 1;
	for(int u : g[v]) {
		if(u == p[v]) continue;
		// cout << "CHILDREN " << v << " " << u << endl;
		p[u] = v;
		dfs(u);
		a[v] ^= 1;
		// cout << "ADDING " << " " << v << endl;
		ans.push_back(v);
	}
	// If a[v] is not good yet5
	
	if(!a[v]) {
		if(v) {
			// non root node
			// if(v == 3) {
			// 	cout << "UWU" << endl;
			// }
			a[p[v]] ^= 1;
			// cout << "ADDING " << " " << p[v] << endl;
			ans.push_back(p[v]);
			a[v] ^= 1;
			ans.push_back(v);
			// cout << "ADDING " << " " << v << endl;
		}else{
			// cout << ":< " << endl;
			// root node
			a[g[v][0]] ^= 1;
			ans.push_back(g[v][0]);
			// cout << "ADDING " << " " << g[v][0] << endl;
			a[v] ^= 1;
			// cout << "ADDING " << " " << v << endl;
			ans.push_back(v);
			a[g[v][0]] ^= 1;
			ans.push_back(g[v][0]);
			// cout << "ADDING " << " " << g[v][0] << endl;
			return;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i = 0;i < N;++i) {
		cin >> a[i];
		a[i] = a[i] == 1;
	}
	a[0] ^= 1;

	for(int i = 0;i < N - 1;++i) {
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0);
	for(int u : ans) {
		cout << (u + 1) << " ";
	}
	cout << endl;
	// cout << a[0] << endl;
}