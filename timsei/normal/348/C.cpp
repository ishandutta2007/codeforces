#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
int n, m, x, y, k, l, q, num, Bl, id[N];
long long A[N], Add[N];
char s[2];
 
vector <int> All[N], Big, who[N];
long long S[N];
 
int cnt[N][355];
 
int main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	Bl = (int) sqrt(n);
	for(int i = 1; i <= m; ++ i) {
		scanf("%d", &num);
		for(int j = 1; j <= num; ++ j) scanf("%d", &x), All[i].push_back(x), S[i] += A[x];
		if(All[i].size() > Bl) {
			Big.push_back(i);
			id[i] = Big.size() - 1;
			for(int j = 0; j < (int) All[i].size(); ++ j) who[All[i][j]].push_back(Big.size() - 1);
		}
	}
	for(int i = 1; i <= m; ++ i) {
		for(int j = 0; j < (int) All[i].size(); ++ j) {
			for(int k = 0; k < (int) who[All[i][j]].size(); ++ k)
				++ cnt[i][who[All[i][j]][k]];
		}
	}
	for(; q --;) {
		scanf("%s", s + 1);
		if(s[1] == '+') {
			scanf("%d%d", &x, &y);
			for(int i = 0; i < (int) Big.size(); ++ i) {
				S[Big[i]] += 1LL * y * cnt[x][i];
			}
			if(All[x].size() <= Bl) {
				for(int j = 0; j < (int) All[x].size(); ++ j) A[All[x][j]] += y;
			}
			else {
				Add[id[x]] += y;
			}
		}
		else if(s[1] == '?') {
			scanf("%d", &x);
			if(All[x].size() > Bl) {
				printf("%lld\n", S[x]);
			}
			else {
				long long ans = 0;
				for(int i = 0; i < (int) All[x].size(); ++ i) ans += A[All[x][i]];
				for(int i = 0; i < (int) Big.size(); ++ i) ans += 1ll * cnt[x][i] * Add[i];
				printf("%lld\n", ans);
			}
		}
	}
}