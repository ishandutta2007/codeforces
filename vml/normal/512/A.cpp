#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

const int maxn = 110;

string s[maxn];

vector <int> ed[30];
set <int> in[30];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int pos = 0;

		while (pos < (int)s[i].size() && pos < (int)s[i + 1].size() && s[i][pos] == s[i + 1][pos]) {
			pos++;
		}

		if (pos == (int)s[i].size()) {
			continue;
		}

		if (pos == (int)s[i + 1].size()) {
			printf("Impossible");
			return 0;
		}

		ed[s[i][pos] - 'a'].push_back(s[i + 1][pos] - 'a');
		in[s[i + 1][pos] - 'a'].insert(s[i][pos] - 'a');
	}

	set <pair <int, int> > s;

	for (int i = 0; i < 26; i++) {
		s.insert(make_pair(in[i].size(), i));
	}

	vector <char> ans;

	while (!s.empty()) {
		int x = (*s.begin()).second;

		if (in[x].size() != 0) {
			printf("Impossible");
			return 0;
		}

		ans.push_back((char)('a' + x));

		s.erase(make_pair(in[x].size(), x));

		for (int i = 0; i < (int)ed[x].size(); i++) {
			int u = ed[x][i];

			s.erase(make_pair(in[u].size(), u));
			in[u].erase(x);
			s.insert(make_pair(in[u].size(), u));
		}
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i];
	}

	return 0;
}