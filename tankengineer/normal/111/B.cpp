#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
#define div DIV
vector<int> div[N];

int rem[N];

int main() {
	for (int i = 1; i <= 100000; ++i) {
		for (int j = i; j <= 100000; j += i) {
			div[j].push_back(i);
		}
	}
	memset(rem, -1, sizeof(rem));
	int n;
	scanf("%d", &n);
	vector<int> xs;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		xs.push_back(x);
		int ans = 0;
		for (int j = 0; j < (int)div[x].size(); ++j) {
			int u = div[x][j];
			++ans;
			if (rem[u] >= i - y) {
				--ans;
			}
			rem[u] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}