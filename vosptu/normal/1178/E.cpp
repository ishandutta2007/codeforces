#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
char S[N];
vector <char> ans;
int n;

int main() {
	scanf("%s", S + 1);
	n = strlen(S + 1);
	int l = 1, r = n;

	while (r - l + 1 >= 4) {
		bool f = false;
		for (int i = 0; i < 4; i++) {
			int x = l + (i % 2 == 1 ? 1 : 0);
			int y = r - (i / 2 == 1 ? 1 : 0);
			if (S[x] == S[y]) {
				f = true;
				ans.push_back(S[x]);
				printf("%c", S[x]);
				break;
			}
		}
		assert(f);
		l += 2;
		r -= 2;
	}
	if (l <= r)
		printf("%c", S[l]);
	for (int i = (int) ans.size() - 1; i >= 0; i--)
		printf("%c", ans[i]);
	printf("\n");
}