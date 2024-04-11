#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

const string FILENAME = "input";

const int MAXN = 2e5 + 1, MAXM = 1 << 20, LOG = 20;

long long sum[MAXN];

int cnt = 1;
int used[MAXM];
int w[MAXM];
int upd[MAXM];
vector<int> elem[MAXM];

long long cur_ans = 0;

void push(int i) {
	if (used[i] != cnt) {
		for (int j : elem[i]) {
			sum[j] += upd[i];
		}
		elem[i].clear();
		used[i] = cnt;
		w[i] = upd[i] = 0;
	}
}

int getw(int i) {
	push(i);
	++upd[i];
	return w[i];
}

int ask(int i) {
	long long ans = getw(i);
	for (int j = 0; j < LOG; ++j) {
		ans += getw(i ^ (1 << j));
	} 
	cur_ans += ans;
	return ans;
}

int n;
int num[MAXN];
int s[MAXN];
vector<int> edge[MAXN];

bool cmp(int i, int j) {
	return s[i] < s[j];
}

int dfs_size_count(int i, int p = -1) {
	s[i] = 1;
	for (int q = 0; q < edge[i].size(); ++q) {
		auto j = edge[i][q];
		if (j == p) {
			swap(edge[i][q], edge[i].back());
			edge[i].pop_back();
			--q;
		} else {
			s[i] += dfs_size_count(j, i);
		}
	}
	sort(edge[i].begin(), edge[i].end(), cmp);
	return s[i];
}

vector<pair<int, int>> mask;

void dfs_mask(int i, int w = 0) {
	w ^= (1 << num[i]);
	mask.pb({w, i});
	for (int j : edge[i]) {
		dfs_mask(j, w);
	}
}

void dfs_solve(int i, int w = 0, int p = -1) {
	++cnt;
	for (int q = 0; q + 1 < edge[i].size(); ++q) {
		auto j = edge[i][q];
		dfs_solve(j, w ^ (1 << num[i]), i);
	}
	cur_ans = 0;
	if (edge[i].size()) {
		auto k = edge[i].back();
		dfs_solve(k, w ^ (1 << num[i]), i);
		cur_ans = 0;
		for (int q = 0; q + 1 < edge[i].size(); ++q) {
			auto j = edge[i][q];
			dfs_mask(j, w);
			for (auto j : mask) {
				sum[j.y] += ask(j.x);
			}
			for (auto j : mask) {
				j.x ^= (1 << num[i]);
				push(j.x);
				sum[j.y] -= upd[j.x];
				elem[j.x].pb(j.y);
				::w[j.x]++;
			}
			mask.clear();
		}
	}
	pair<int, int> j = {w, i};
	sum[j.y] += ask(j.x);
	j.x ^= (1 << num[i]);
	push(j.x);
	sum[j.y] -= upd[j.x];
	elem[j.x].pb(j.y);
	++::w[j.x];
	sum[i] -= cur_ans;
	if (p != -1) sum[p] -= cur_ans;
}

long long dfs_push(int i) {
	for (int j : edge[i]) {
		sum[i] += dfs_push(j);
	}
	return sum[i];
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		num[i] = c - 'a';
	}
	dfs_size_count(0);
	dfs_solve(0);
	++cnt;
	for (int i = 0; i < MAXM; ++i) push(i);
	dfs_push(0);
	for (int i = 0; i < n; ++i) {
		cout << sum[i] + 1 << ' ';
	}
	cout << '\n';
}