#include <cstdio>
#include <vector>
#include <algorithm>

char txt[200200], p[200200];

int suf[200200], pref[200200];
std::vector<int> pos[256];

int main() {
	scanf(" %s %s", txt + 1, p + 1);
	int n = 0;
	int m = 0;
	while(txt[n + 1] != 0) n++;
	while(p[m + 1] != 0) m++;
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		if(txt[i] == p[pref[i] + 1]) pref[i]++;
	}
	suf[n + 1] = m + 1;
	for(int i = n; i > 0; i--) {
		suf[i] = suf[i + 1];
		if(txt[i] == p[suf[i] - 1]) suf[i]--;
	}
	for(int i = 1; i <= m; i++) {
		pos[p[i]].push_back(i);
	}
	bool ans = true;
	for(int i = 1; i <= n; i++) {
		int idx = std::upper_bound(pos[txt[i]].begin(), pos[txt[i]].end(), pref[i]) - pos[txt[i]].begin();
		if(idx == 0) {
			ans = false;
			break;
		}
		idx--;
		ans = ans && pos[txt[i]][idx] + 1 >= suf[i + 1];
	}
	if(ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}