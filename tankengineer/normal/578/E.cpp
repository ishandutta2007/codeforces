#include<cassert>
#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

char s[N];

void solve(int &ans, vector<int> &path) {
	int n = strlen(s);
	set<int> pl, pr;
	char cur = s[0];
	int pos = 0;
	for (int i = 1; i < n; ++i) {
		if (s[i] == 'L') {
			pl.insert(i);
		} else {
			pr.insert(i);
		}
	}
	ans = 0;	
	while (pl.size() || pr.size()) {
		if (cur == 'L') {
			assert(pr.size());
			if (pr.lower_bound(pos) == pr.end() || pr.upper_bound(*pr.lower_bound(pos)) == pr.end() && pl.upper_bound(*pr.lower_bound(pos)) == pl.end() && (pl.size() != 0 && *pr.begin() < *pl.begin())) {
				++ans;
				pos = *pr.begin();
			} else {
				pos = *pr.lower_bound(pos);
			}
			pr.erase(pos);
			cur = 'R';
		} else {
			assert(pl.size());
			if (pl.lower_bound(pos) == pl.end() || pl.upper_bound(*pl.lower_bound(pos)) == pl.end() && pr.upper_bound(*pl.lower_bound(pos)) == pr.end() && (pr.size() != 0 && *pl.begin() < *pr.begin())) {
				++ans;
				pos = *pl.begin();
			} else {
				pos = *pl.lower_bound(pos);
			}
			pl.erase(pos);
			cur = 'L';
		}
		path.push_back(pos);
	}
}

int main() {
	scanf("%s",	s + 1);
	/*
	{
		int n = rand() % 10000 + 1;
		int cl = n / 2, cr = n - cl;
		if (rand() & 1) {
			swap(cl, cr);
		}
		for (int i = 1; i <= n; ++i) {
			if (cl == 0) {
				s[i] = 'R';
				--cr;
			} else if (cr == 0) {
				s[i] = 'L';
				--cl;
			} else {
				if (rand() & 1) {
					s[i] = 'L';
					--cl;
				} else {
					s[i] = 'R';
					--cr;
				}
			}
		}
	}*/
	int n = strlen(s + 1);
	//cout << n << ' ' << s << endl;
	int cl = 0, cr = 0;
	for (int i = 1; i <= n; ++i) {
		cl += s[i] == 'L';
		cr += s[i] == 'R';
	}
	int ans = 0;
	vector<int> path;
	if (cl == cr + 1) {
		s[0] = 'R';
		solve(ans, path);
	} else if (cl + 1 == cr) {
		s[0] = 'L';
		solve(ans, path);
	} else {
		assert(cl == cr);
		int ans1, ans2;
		vector<int> path1, path2;
		s[0] = 'R';
		solve(ans1, path1);
		s[0] = 'L';
		solve(ans2, path2);
		if (ans1 < ans2) {
			ans = ans1;
			path = path1;
			s[0] = 'R';
		} else {
			ans = ans2;
			path = path2;
			s[0] = 'L';
		}
	}
	printf("%d\n", ans);
	int cnt = 0;
	for (int i = 0; i < (int)path.size(); ++i) {
		printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
		cnt += i && path[i] < path[i - 1];
		assert(!i || s[path[i]] != s[path[i - 1]]);
	}
	assert(cnt == ans);
	return 0;
}