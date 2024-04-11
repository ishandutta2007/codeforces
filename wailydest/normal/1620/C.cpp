#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

const int N = 2000;
int t, n, k;
long long x;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%lld%s", &n, &k, &x, s);
		--x;
		std::vector<int> r;
		for (int i = 0; s[i];) {
			r.push_back(0);
			while (s[i] == '*') {
				++i;
				++r.back();
			}
			r.back() = r.back() * k + 1;
			if (s[i]) {
				++i;
				if (!s[i]) r.push_back(1);
			}
		}
		std::string ans;
		for (int i = (int)r.size() - 1; i >= 0; --i) {
			for (int j = 0; j < x % r[i]; ++j) ans.push_back('b');
			if (i) ans.push_back('a');
			x /= r[i];
		}
		std::reverse(ans.begin(), ans.end());
		printf("%s\n", ans.c_str());
	}
	return 0;
}