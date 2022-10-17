#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

const int N = 2000;
const int A = 26;
char s[N + 1];
int cnt[A];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		vector<int> di;
		for (int i = 1; i <= max(n, k); ++i) if (!(k % i)) di.push_back(i);
		for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
		bool ok = false;
		for (int l = n; l > 0 && !ok; --l) {
			for (auto i : di) if (!(l % i)) {
				int amt = 0;
				for (int j = 0; j < A; ++j) amt += cnt[j] / (l / i);
				if (amt >= i) {
					ok = true;
					printf("%d\n", l);
					break;
				}
			}
		}
		memset(cnt, 0, 4 * A);
	}
	return 0;
}