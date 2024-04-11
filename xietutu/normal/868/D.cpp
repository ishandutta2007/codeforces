#include <bits/stdc++.h>
using namespace std;
const int K = 13;
#define PB push_back
int n, m;
char s[105];
vector<int> sta[205][14];
string pre[205], suf[205];
bool exceed[205];
inline void Unit(vector<int>& vec) {
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		for (int j = 0; j < len; ++j) {
			int ret = 0;
			for (int k = j; k < len; ++k) {
				if (k - j + 1 > K) break;
				if (s[k] == '1') ret |= 1 << (k - j);
				sta[i][k - j + 1].PB(ret);
			}		
		}
		for (int j = 1; j <= min(len, K); ++j) Unit(sta[i][j]);
		
		for (int j = 0; j < min(len, K); ++j) {
			pre[i] += s[j];
			suf[i] += s[len - 1 - j];
		}
	}
	
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int a, b, ans = 0;
		scanf("%d%d", &a, &b);
		for (int j = 1; j <= suf[a].size(); ++j) {
			int reta = 0;
			for (int l = 0; l < j; ++l)
				reta += (suf[a][l] - '0') << (j - 1 - l);
				
			int retb = 0;
			for (int k = 1; k <= pre[b].size(); ++k) {
				retb += (pre[b][k - 1] - '0') << (k - 1);
				if (j + k > K) break;
				sta[i + n][j + k].PB(reta + (retb << j)); 
			}
		}
		
		for (int len = 1; len <= K; ++len) {
			for (auto v : sta[a][len])
				sta[i + n][len].PB(v);
			for (auto v : sta[b][len])
				sta[i + n][len].PB(v);
			Unit(sta[i + n][len]);
		}
		
		pre[i + n] = pre[a];
		int p = 0;
		while (pre[i + n].size() < K && p < pre[b].size()) {
			pre[i + n] += pre[b][p++];
		}
		
		suf[i + n] = suf[b];
		p = 0;
		while (suf[i + n].size() < K && p < suf[a].size()) {
			suf[i + n] += suf[a][p++];
		}
		
		for (int len = 1; len <= K; ++len) {
			if (sta[i + n][len].size() < (1 << len)) break;
			ans = len;
		}
		printf("%d\n", ans);
	}
}