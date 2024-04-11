#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<int> edges[100000];
vector<pair<int, int> > st0;
int color[100000], ans[100000][2], cnt[100000];
int modulo(1e9 + 7);
void psh(int v) {
	st0.push_back(make_pair(v, 0));
}
int inv(int x) {
	if(x == 1)
		return 1;
	else
		return (long long)inv(x - modulo % x) * ((modulo + x - 1) / x) % modulo;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i(0); i < n - 1; i++) {
		int x;
		scanf("%d", &x);
		edges[x].push_back(i + 1);
	}
	for(int i(0); i < n; i++) {
		scanf("%d", &color[i]);
	}
	fill(cnt, cnt + n, 0);
	memset(ans, 0, sizeof(ans));
	psh(0);
	while(!st0.empty()) {
		int v(st0.back().first), p(st0.back().second++);
		if(p != (int)edges[v].size()) {
			psh(edges[v][p]);
		}else {
			if(color[v]) {
				ans[v][0] = 1;
				for(int i(0); i < (int)edges[v].size(); i++) {
					ans[v][0] = (long long)ans[v][0] * ans[edges[v][i]][0] % modulo;
				}
				ans[v][1] = ans[v][0];
			}else {
				int tmp(1);
				for(int i(0); i < (int)edges[v].size(); i++) {
					tmp = (long long)tmp * ans[edges[v][i]][0] % modulo;
				}
				ans[v][1] = 0;
				for(int i(0); i < (int)edges[v].size(); i++) {
					ans[v][1] = (ans[v][1] + (long long)tmp * inv(ans[edges[v][i]][0]) % modulo * ans[edges[v][i]][1] % modulo) % modulo;
				}
				ans[v][0] = 1;
				for(int i(0); i < (int)edges[v].size(); i++) {
					ans[v][0] = (long long)ans[v][0] * ans[edges[v][i]][0] % modulo;
				}
				ans[v][0] = (ans[v][0] + ans[v][1]) % modulo;
			}
			st0.pop_back();
		}
	}
	cout << ans[0][1] << endl;
	fclose(stdin);
	return 0;
}