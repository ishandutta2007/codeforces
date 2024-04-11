#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;

vector<int> g;
vector<bool> used;

vector<int> colors;

int ans = INT_MAX;

vector<int> loop;
vector<bool> gcds;
vector<int> divs;

void getdivs(int n) 
{
	for (int i = 1; i <= n; ++i) if (!(n % i)) divs.push_back(i);
}

void check(int v) 
{
	int i = v;
	used[v] = true;
	loop.push_back(i);
	while (g[i] != v) {
		i = g[i];
		used[i] = true;
		loop.push_back(i);
	}
	int sz = loop.size();
	getdivs(sz);
	for (int i = 0; i < divs.size() && i < ans; ++i) {
		for (int j = 0; j < divs[i]; ++j) {
			int k;
			for (k = (j + divs[i]) % sz; k != j && colors[loop[k]] == colors[loop[j]]; k = (k + divs[i]) % sz);
			if (k == j) ans = min(ans, divs[i]);
		}
	}
	loop.clear();
	divs.clear();
}

void solve() 
{
	ans = INT_MAX;
	cin >> n;
	g.resize(n);
	colors.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
		--g[i];
	}
	for (int i = 0; i < n; ++i) cin >> colors[i];
	for (int i = 0; i < n; ++i) if (!used[i]) check(i);
	cout << ans << '\n';
	g.clear();
	colors.clear();
	used.clear();
}

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}