#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> amt(k);
	int val;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &val);
		++amt[val - 1];
	}
	vector<int> c(k);
	for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
	vector<vector<int> > testcase;
	vector<int> count;
	for (int i = k - 1; i >= 0; --i) {
		if (amt[i]) {
			int cur = upper_bound(count.begin(), count.end(), c[i], greater<int>()) - count.begin();
			if (cur == count.size()) {
				testcase.push_back(vector<int>());
				count.push_back(0);
			}
			while (amt[i]--) {
				if (count[cur] == c[i]) {
					++cur;
					if (cur == count.size()) {
						testcase.push_back(vector<int>());
						count.push_back(0);
					}
				}
				testcase[cur].push_back(i);
				++count[cur];
			}
		}
	}
	printf("%d\n", testcase.size());
	for (int i = 0; i < testcase.size(); ++i) {
		printf("%d ", testcase[i].size());
		for (int j = 0; j < testcase[i].size(); ++j) printf("%d ", testcase[i][j] + 1);
		printf("\n");
	}
	return 0;
}