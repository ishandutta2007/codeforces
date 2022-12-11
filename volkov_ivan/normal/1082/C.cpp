#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 7;
vector <int> p[MAX_N];

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s, r;
		cin >> s >> r;
		p[s].push_back(r);
	}
	set <int> poss;
	for (int i = 1; i <= m; i++) poss.insert(i);
	long long s = 0, ans = 0;
	for (int i = 1; i <= m; i++) sort(p[i].begin(), p[i].end(), greater <int> ());
	for (int i = 0; i < n; i++) {
		vector <int> del;
		s = 0;
		for (int j : poss) {
			if (p[j].size() == i) {
				del.push_back(j);
				continue;
			}
			if (i != 0) p[j][i] += p[j][i - 1];	
			if (p[j][i] > 0) s += p[j][i];
		}
		ans = max(ans, s);
		for (int elem : del) poss.erase(elem);
	}
	cout << ans << endl;
	return 0;
}