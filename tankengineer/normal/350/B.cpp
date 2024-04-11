#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int type[N], fa[N], dgr[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", type + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", fa + i);
		--fa[i];
		if (fa[i] != -1) {
			dgr[fa[i]]++;
		}
	}
	int ans = -1, start = 0;
	for (int i = 0; i < n; ++i) {
		if (type[i] == 1) {
			int t = i, l = 1;
			while (fa[t] != -1 && dgr[fa[t]] == 1) {
				t = fa[t];
				++l;
			}
			if (ans < l) {
				ans = l;
				start = i;
			}
		}
	}
	vector<int> v;
	v.push_back(start);
	int p = start;
	while (fa[p] != -1 && dgr[fa[p]] == 1) {
		p = fa[p];
		v.push_back(p);
	}
	printf("%d\n", (int)v.size());
	for (int i = (int)v.size() - 1; i >= 0; --i) {
		printf("%d%c", v[i] + 1, i == 0 ? '\n' : ' ');
	}
	return 0;
}