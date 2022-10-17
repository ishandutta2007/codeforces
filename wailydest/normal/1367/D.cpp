#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		bool used[51] = {0};
		char s[51];
		int n;
		scanf("%s%d", s, &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		vector<int> amt;
		vector<int> pos;
		int sum = 0;
		while (sum != n) {
			amt.push_back(0);
			int len = pos.size();
			for (int i = 0; i < n; ++i) if (!used[i]) {
				int th = 0;
				for (int j = 0; j < len; ++j) th += abs(i - pos[j]);
				if (th == a[i]) {
					pos.push_back(i);
					++amt.back();
					used[i] = true;
				}
			}
			sum += amt.back();
		}
		int total[26] = {0};
		for (int i = 0; s[i]; ++i) ++total[s[i] - 'a'];
		vector<int> let(amt.size());
		int j = 25;
		for (int i = 0; i < amt.size(); ++i, --j) {
			while (amt[i] > total[j]) --j;
			let[i] = j;
		}
		int ans[50];
		j = 0;
		for (int i = 0; i < amt.size(); ++i) {
			for (int k = 0; k < amt[i]; ++k, ++j) ans[pos[j]] = let[i];
		}
		for (int i = 0; i < n; ++i) printf("%c", 'a' + ans[i]);
		printf("\n");
	}
	return 0;
}