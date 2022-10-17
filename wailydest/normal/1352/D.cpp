#include <cstdio>
#include <deque>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		deque<int> d;
		int val;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &val);
			d.push_back(val);
		}
		int m = 0;
		int e[2] = {0, 0};
		int c[2] = {0, 0};
		while (!d.empty()) {
			while (!d.empty() && c[m & 1] <= c[(m & 1) ^ 1]) {
				if (m & 1) {
					c[1] += d.back();
					d.pop_back();
				}
				else {
					c[0] += d.front();
					d.pop_front();
				}
			}
			e[m & 1] += c[m & 1];
			c[(m & 1) ^ 1] = 0;
			++m;
		}
		printf("%d %d %d\n", m, e[0], e[1]);
	}
	return 0;
}