#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int S[N], n, tmp[N];

int A[N], B[N], l, r;

vector <int> v[N], id;

bool cmp(int x, int y) {
	return v[x].size() > v[y].size();
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) v[i].clear(); id.clear();
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), v[A[i]].push_back(i), id.push_back(A[i]);
	sort(id.begin(), id.end());
	id.erase(unique(id.begin(), id.end()), id.end());
	sort(id.begin(), id.end(), cmp);
	int tot = 0;
	while(id.size() > 1) {
		++ tot;
		vector <int> all;
		for(int i = 0; i < (int) id.size(); ++ i) {
			all.push_back(v[id[i]].back());
			v[id[i]].pop_back();
		}
		while(id.size() && !v[id.back()].size()) id.pop_back();
		B[all[0]] = A[all.back()];
		for(int i = 1; i < (int) all.size(); ++ i) {
			B[all[i]] = A[all[i - 1]];
		}
	}
	if(id.size())
	for(auto x : v[id[0]]) B[x] = A[x];
	for(int i = 1; i <= n; ++ i)printf("%d ", B[i]);
	puts("");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}