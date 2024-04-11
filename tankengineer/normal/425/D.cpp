#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 100000;

int n;

vector<int> xpos[L + 1], ypos[L + 1];

bool valve = false;

bool exist(int x, int y) {
	if (x < 0 || x > L || y < 0 || y > L) {
		return false;
	}
	if (!valve) {
		int t = lower_bound(xpos[x].begin(), xpos[x].end(), y) - xpos[x].begin();
		return t < xpos[x].size() && xpos[x][t] == y;
	} else {
		int t = lower_bound(ypos[x].begin(), ypos[x].end(), y) - ypos[x].begin();
		return t < ypos[x].size() && ypos[x][t] == y;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		xpos[x].push_back(y);
	}
	for (int i = 0; i <= L; ++i) {
		sort(xpos[i].begin(), xpos[i].end());
	}
	int ans = 0;
	for (int i = 0; i <= L; ++i) {
		vector<int> &pos = xpos[i];
		if ((long long)pos.size() * pos.size() <= n) {
			for (int j = 0; j < (int)pos.size(); ++j) {
				for (int k = j + 1; k < (int)pos.size(); ++k) {
					int d = pos[k] - pos[j];
					ans += exist(i + d, pos[k]) && exist(i + d, pos[j]);
					ans += exist(i - d, pos[k]) && exist(i - d, pos[j]);
				}
			}
			pos.clear();
		}
	}
	valve = true;
	for (int i = 0; i <= L; ++i) {
		for (int j = 0; j < (int)xpos[i].size(); ++j) {
			ypos[xpos[i][j]].push_back(i);
		}
	}
	for (int i = 0; i <= L; ++i) {
		vector<int> &pos = ypos[i];
		for (int j = 0; j < (int)pos.size(); ++j) {
			for (int k = j + 1; k < (int)pos.size(); ++k) {
				int d = pos[k] - pos[j];
				ans += exist(i + d, pos[k]) && exist(i + d, pos[j]);
				ans += exist(i - d, pos[k]) && exist(i - d, pos[j]);
			}
		}
		pos.clear();
	}
	printf("%d\n", ans);
	return 0;
}