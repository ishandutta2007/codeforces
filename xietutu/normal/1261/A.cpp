#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int n, K;
char s[2005];

vector <pii> Ans;

int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		scanf("%d%d", &n, &K);
		scanf("%s", s + 1);
		int nums = n / 2 - K + 1;
		
//		printf("%d\n", nums);
		
		Ans.clear();
		int now = 1;
		for (int i = 1; i <= nums; ++ i) {
			if (s[now] != '(') {
				for (int j = now + 1; j <= n; ++ j)
					if (s[j] == '(') {
						Ans.push_back(pii(now, j));
						reverse(s + now, s + j + 1);
						break;
					}
			}
			++ now;
		}
		for (int i = 1; i <= nums; ++ i) {
			if (s[now] != ')') {
				for (int j = now + 1; j <= n; ++ j)
					if (s[j] == ')') {
						Ans.push_back(pii(now, j));
						reverse(s + now, s + j + 1);
						break;
					}
			}
			++ now;
		}
		int tp = 1;
		while (now <= n) {
			if (tp ^ (s[now] == '(')) {
				for (int j = now + 1; j <= n; ++ j)
					if (!(tp ^ (s[j] == '('))) {
						Ans.push_back(pii(now, j));
						reverse(s + now, s + j + 1);
						break;
					}
			}
			tp ^= 1;
			++ now;
		}
		
	//	printf("%s\n", s + 1);
		
		printf("%d\n", (int)Ans.size());
		for (auto x : Ans) {
			printf("%d %d\n", x.first, x.second);
		}
	}
	return 0;
}