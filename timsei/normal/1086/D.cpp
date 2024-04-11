#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define lowbit(x) (x & (-x))

struct BIT {
	int S[N];
	void init() {
		memset(S, 0, sizeof(S));
	}
	void add(int x, int v) {
		for(int i = x; i < N; i += lowbit(i))
		S[i] += v;
	}
	int Sum(int x) {
		int res = 0;
		for(int i = x; i; i -= lowbit(i))
		res += S[i];
		return res;
	}
}B[3];

int n, q, x, y, D[129];
char s[N];
set <int> A[3];

int calc(void) {
	int ans = 0;
	for(int i = 0; i < 3; ++ i) {
		int Win = (i + 2) % 3, Lose = (i + 1) % 3;
		if(!A[Lose].size()) 
		ans += B[i].Sum(n);
		if(!A[Lose].size())continue;
		if(A[Win].size()) {
			int l1 = (*A[Win].begin()), r1 = (*A[Win].rbegin()), 
			l2 = (*A[Lose].begin()), r2 = (*A[Lose].rbegin());
			vector < pair <int, int> > Die;
			Die.clear();
			if(l2 < l1) Die.push_back(make_pair(l2, l1 - 1));
			if(r2 > r1) Die.push_back(make_pair(r1 + 1, r2));
			ans += B[i].Sum(n);
			if(Die.size() == 2) {
				if(Die[0].first > Die[1].first) swap(Die[0], Die[1]);
				if(Die[0].second >= Die[1].first) {
					Die[0].second = max(Die[0].second, Die[1].second);
					Die.pop_back();
				}
			}
			for(int j = 0; j < Die.size(); ++ j) {
				ans -= (B[i].Sum(Die[j].second) - B[i].Sum(Die[j].first - 1));
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> q;
	scanf("%s", s + 1);
	D['R'] = 0, D['P'] = 1, D['S'] = 2;
	memset(B, 0, sizeof(B));
	for(int i = 1; i <= n; ++ i) {
		s[i] = D[s[i]];
		B[s[i]].add(i, 1);
		A[s[i]].insert(i);
	}
	printf("%d\n", calc());
	char c;
	for(; q --;) {
		scanf("%d %c", &x, &c);
		c = D[c];
		B[s[x]].add(x, -1);
		A[s[x]].erase(x);
		s[x] = c;
		B[s[x]].add(x, 1);
		A[s[x]].insert(x);
		printf("%d\n", calc());
	}
}