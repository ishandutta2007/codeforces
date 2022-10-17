#include <iostream>
#include <string>
#include <vector>
using namespace std;

int steps(string &from, string &to) 
{
	int cnt = 0;
	for (int i = 0; i < 7; ++i) {
		if (from[i] == '1' && to[i] == '0') return -1;
		if (to[i] == '1' && from[i] == '0') ++cnt;
	}
	return cnt;
}

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<vector<pair<int, int> > > to(n);
	char buf[8];
	string s;
	int st;
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		s = buf;
		for (int j = 0; j < 10; ++j) {
			st = steps(s, digits[j]);
			if (st != -1) to[i].push_back(make_pair(j, st));
		}
	}
	vector<vector<bool> > pos(n, vector<bool>(k + 1));
	for (int i = 0; i < to[n - 1].size(); ++i) if (to[n - 1][i].second <= k) pos[n - 1][to[n - 1][i].second] = true;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= k; ++j) if (pos[i + 1][j]) {
			for (int p = 0; p < to[i].size(); ++p) if (to[i][p].second + j <= k) pos[i][to[i][p].second + j] = true;
		}
	}
	if (!pos[0][k]) {
		printf("-1\n");
		return 0;
	}
	vector<int> ans(n);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = to[i].size() - 1; j >= 0; --j) if (k - to[i][j].second >= 0 && pos[i + 1][k - to[i][j].second]) {
			ans[i] = to[i][j].first;
			k -= to[i][j].second;
			break;
		}
	}
	for (int i = to[n - 1].size() - 1; i >= 0; --i) {
		if (to[n - 1][i].second == k) {
			ans[n - 1] = to[n - 1][i].first;
			break;
		}
	}
	for (int i = 0; i < n; ++i) printf("%d", ans[i]);
	printf("\n");
	return 0;
}