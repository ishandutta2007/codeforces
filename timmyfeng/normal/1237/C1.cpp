#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, map<int, vector<pair<int, int>>>> mp;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		mp[x][y].emplace_back(z, i);
	}
	
	vector<pair<int, int>> fin;
	for (auto& i : mp) {
		vector<pair<int, int>> left;

		for (auto& j : i.second) {
			sort(j.second.begin(), j.second.end());

			int k = 0;
			for ( ; k + 1 < int(j.second.size()); k += 2) {
				cout << j.second[k].second << " " << j.second[k + 1].second << "\n";
			}

			if (k < int(j.second.size())) {
				left.emplace_back(j.first, j.second[k].second);
			}
		}

		sort(left.begin(), left.end());

		int j = 0;
		for ( ; j + 1 < int(left.size()); j += 2) {
			cout << left[j].second << " " << left[j + 1].second << "\n";
		}

		if (j < int(left.size())) {
			fin.emplace_back(i.first, left[j].second);
		}
	}
	
	sort(fin.begin(), fin.end());

	int i = 0;
	for ( ; i < int(fin.size()); i += 2) {
		cout << fin[i].second << " " << fin[i + 1].second << "\n";
	}
}