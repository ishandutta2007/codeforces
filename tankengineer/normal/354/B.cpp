#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int N = 21;
int n, val[N][N];
char chr[N][N];
map<vector<pair<int, int> >, int> mem;

bool byChar(pair<int, int> a, pair<int, int> b) {
	return chr[a.first][a.second] < chr[b.first][b.second];
}

int go(vector<pair<int, int> > pos) {
	if (mem.count(pos)) {
		return mem[pos];
	}
	if (pos.front().first == n - 1 && pos.front().second == n - 1) {
		return val[n - 1][n - 1];
	}
	vector<pair<int, int> > ch;	
	for (int i = 0; i < (int)pos.size(); ++i) {
		int x = pos[i].first, y = pos[i].second;
		if (x != n - 1) {
			ch.push_back(make_pair(x + 1, y));
		}
		if (y != n - 1) {
			ch.push_back(make_pair(x, y + 1));
		}
	}
	sort(ch.begin(), ch.end());
	ch.erase(unique(ch.begin(), ch.end()), ch.end());
	sort(ch.begin(), ch.end(), byChar);
	int col = pos.front().first + pos.front().second & 1;
	int ret = col ? INT_MIN : INT_MAX;
	for (int i = 0; i < (int)ch.size(); ++i) {
		vector<pair<int, int> > sch;
		int j = i;
		while (j < (int)ch.size() && chr[ch[i].first][ch[i].second] == chr[ch[j].first][ch[j].second]) {
			sch.push_back(ch[j]);
			++j;
		}
		sort(sch.begin(), sch.end());
		i = j - 1;
		if (col) {
			ret = max(ret, go(sch));
		} else {
			ret = min(ret, go(sch));
		}
	}
	ret += val[pos.front().first][pos.front().second];
	mem[pos] = ret;
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", chr[i]);
		for (int j = 0; j < n; ++j) {
			val[i][j] = 0;
			if (chr[i][j] == 'a') {
				val[i][j] = 1;
			} else if (chr[i][j] == 'b') {
				val[i][j] = -1;
			}
		}
	}
	vector<pair<int, int> > pos;
	pos.push_back(make_pair(0, 0));
	int dp = go(pos);
	if (dp > 0) {
		printf("FIRST\n");
	} else if (dp == 0) {
		printf("DRAW\n");
	} else {
		printf("SECOND\n");
	}
	return 0;
}