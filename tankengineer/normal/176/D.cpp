#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005, M = 1000005;
int n, m, h[N], dp[N], len[N], slen[N];
vector<vector<int> > next[N], sum, hsum;
char s[M];

void init(vector<vector<int> > &next) {
	int l = strlen(s);
	vector<int> cnt;
	for (int i = 0; i < 26; ++i) {
		cnt.push_back(0);
	}
	for (int i = 0; i < l; ++i) {
		++cnt[s[i] - 'a'];
	}
	sum.push_back(cnt);
	vector<int> nxt;
	for (int i = 0; i < 26; ++i) {
		nxt.push_back(-1);
	}
	for (int i = l - 1; i >= 0; --i) {
		nxt[s[i] - 'a'] = i;
		next.push_back(nxt);
	}
	reverse(next.begin(), next.end());
}

int findNext(int pos, int ch) {
	int bpos = upper_bound(slen, slen + m + 1, pos) - slen;
	if (bpos > m) {
		return -1;
	}
	int bp = h[bpos - 1], spos = pos - slen[bpos - 1];
	if (next[bp][spos][ch] != -1) {
		return slen[bpos - 1] + next[bp][spos][ch];
	}
	if (hsum[m][ch] == hsum[bpos][ch]) {
		return -1;
	}
	int l = bpos, r = m, mid;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (hsum[mid][ch] > hsum[bpos][ch]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return slen[l - 1] + next[h[l - 1]][0][ch];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		len[i] = strlen(s);
		init(next[i]);
	}
	scanf("%d", &m);
	vector<int> tsum;
	for (int j = 0; j < 26; ++j) {
		tsum.push_back(0);
	}
	hsum.push_back(tsum);
	for (int i = 0; i < m; ++i) {
		scanf("%d", h + i);
		--h[i];
		vector<int> tsum;
		for (int j = 0; j < 26; ++j) {
			tsum.push_back(hsum.back()[j] + sum[h[i]][j]);
		}
		hsum.push_back(tsum);
		slen[i + 1] = slen[i] + len[h[i]];
	}
		
	scanf("%s", s);
	int l = strlen(s);
	dp[0] = -1;
	for (int i = 1; i <= l; ++i) {
		dp[i] = -2;
	}
	for (int i = 0; i < l; ++i) {
		for (int j = i; j >= 0; --j) {
			int st = dp[j] + 1;
			if (st < 0) {
				continue;
			}
			int nt = findNext(st, s[i] - 'a');
			if (nt < 0) {
				continue;
			}
			if (dp[j + 1] < 0 || dp[j + 1] > nt) {
				dp[j + 1] = nt;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= l; ++i) {
		if (dp[i] + 1 >= 0) {
			ans = max(ans, i);
		}
	}
	printf("%d\n", ans);
	return 0;
}