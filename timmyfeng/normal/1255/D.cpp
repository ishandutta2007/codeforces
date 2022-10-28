#include <bits/stdc++.h>
using namespace std;
char id[62];
int main() {
	int ndx = 0;
	for (char i = '0'; i <= '9'; ++i) {
		id[ndx++] = i;
	}
	for (char i = 'A'; i <= 'Z'; ++i) {
		id[ndx++] = i;
	}
	for (char i = 'a'; i <= 'z'; ++i) {
		id[ndx++] = i;
	}

    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	vector<string> farm;
	while (tt--) {
		int r, c, k;
		cin >> r >> c >> k;
		farm.resize(r);
		int per = 0;
		for (auto& i : farm) {
			cin >> i;
			per += count(i.begin(), i.end(), 'R');
		}
		int lessCt = k - per % k;
		per /= k;
		
		int i = 0;
		int ct = 0;
		for (int k = 0; k < r; ++k) {
			for (int j = 0; j < c; ++j) {
				int _j = (k % 2 ? c - 1 - j : j);
				ct += (farm[k][_j] == 'R');
				if (lessCt && ct > per || ct > per + 1) {
					ct = 1;
					if (lessCt) {
						--lessCt;
					}
					++i;
				}
				farm[k][_j] = id[i];
			}
		}

		for (auto& i : farm) {
			cout << i << '\n';
		}
	}
}