#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200;
char s[MAXN];
vector <int> ans[MAXN]; int top;
vector <int> v[2];

int main () {
	scanf("%s", s + 1); int i, j;
	int n = strlen(s + 1);
	for (i = 1; i <= n; i++) {
		if (s[i] == '0') {
			if (!v[1].empty()) ans[v[1].back()].push_back(i), v[0].push_back(v[1].back()), v[1].pop_back();
			else ans[++top].push_back(i), v[0].push_back(top);
		}
		else if (!v[0].empty()) {
			ans[v[0].back()].push_back(i), v[1].push_back(v[0].back()), v[0].pop_back();
		}
		else { puts("-1"); return 0; }
	}
	if (v[1].size()) { puts("-1"); return 0; }
	printf("%d\n", top);
	for (i = 1; i <= top; i++) {
		printf("%d ", ans[i].size());
		for (auto j: ans[i]) printf("%d ", j); putchar('\n');
	}
	return 0;
}