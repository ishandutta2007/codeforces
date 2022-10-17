#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define ll long long

const int LIM = 100000, MAXN = LIM + 500;
int p[MAXN], top; bool np[MAXN];
void genp () {
	int i, j;
	for (i = 2; i <= LIM; i++) {
		if (!np[i]) p[++top] = i;
		for (j = 1; j <= top; j++) {
			if (p[j] * i > LIM) break;
			np[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

#define pii pair<int, int>
vector <pii> ans;

int main () {
	genp(); int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) np[i] = 0;
	vector <int> even;
	for (i = top; i >= 1; i--) if (2 * p[i] <= n) {
		vector <int> v;
		for (j = 1; j * p[i] <= n; j++) if (!np[p[i] * j]) np[p[i] * j] = 1, v.push_back(p[i] * j);
		reverse(v.begin(), v.end());
		if (v.size() & 1) { v.pop_back(); even.push_back(v.back()); v.pop_back(); v.push_back(p[i]); }
		while (!v.empty()) j = v.back(), v.pop_back(), ans.push_back(make_pair(j, v.back())), v.pop_back();
	}
	while (even.size() >= 2) i = even.back(), even.pop_back(), ans.push_back(make_pair(i, even.back())), even.pop_back();
	printf("%d\n", ans.size()); for (auto i: ans) printf("%d %d\n", i.first, i.second); 
	return 0;
}