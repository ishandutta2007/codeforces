#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000;
int n, hp, reg, bar[N], dmg[N];
bool used[N];

int main() {
	scanf("%d%d%d", &n, &hp, &reg);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", bar + i, dmg + i);
		used[i] = false;
	}
	int cur = hp, dmg_sum = 0, timer = 0;
	bool flag = false;	
	vector<pair<int, int> > ans;
	while (cur > 0 && !flag) {
		cur -= dmg_sum;
		cur += reg;
		cur = min(cur, hp);	
		if (cur <= 0) {
			break;
		}
		int choose = -1;
		for (int i = 0; i < n; ++i) {
			if (!used[i] && cur * 100 <= hp * bar[i]) {
				if (choose == -1 || dmg[i] > dmg[choose]) {
					choose = i;
				}
			}
		}
		if (choose != -1) {
			used[choose] = true;
			dmg_sum += dmg[choose];
			ans.push_back(make_pair(timer, choose + 1));
		} else {
			if (cur == hp) {
				flag = true;
			}
		}
		++timer;
	}
	if (flag) {
		puts("NO");
	} else {
		puts("YES");
		printf("%d %d\n", timer, (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}