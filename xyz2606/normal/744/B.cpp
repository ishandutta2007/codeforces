#include<bits/stdc++.h>
using namespace std;
int ans[10][2][1111];
int n;
void ask(vector<int> & q, int * ans) {
	if(q.empty()) {
		for(int i(1); i <= n; i++) {
			ans[i] = 1e9;
		}
	}else {
		printf("%d\n", (int)q.size());
		for(int i(0); i < (int)q.size(); i++) {
			printf("%d%c", q[i], i == (int)q.size() - 1 ? '\n' : ' ');
		}
		fflush(stdout);
		for(int i(1); i <= n; i++) {
			scanf("%d", &ans[i]);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int d(0); d < 2; d++) {
		for(int i(0); i < 10; i++) {
			vector<int> q;
			for(int j(1); j <= n; j++) {
				if((j >> i & 1) == d) {
					q.push_back(j);
				}
			}
			ask(q, ans[i][d]);
		}
	}
	printf("-1\n");
	for(int i(1); i <= n; i++) {
		int res(1e9);
		for(int j(0); j < 10; j++) {
			res = min(res, ans[j][1 ^ (i >> j & 1)][i]); 
		}
		printf("%d%c", res, i == n ? '\n' : ' ');
	}
	fflush(stdout);
}