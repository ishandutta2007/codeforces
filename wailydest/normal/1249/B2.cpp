#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 200000;

int p[N];
int len[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			--p[i];
		}
		for (int i = 0; i < n; ++i) {
			if (!len[i]) {
				vector<int> loop;
				int v = i;
				do {
					loop.push_back(v);
					v = p[v];
				} while (v != loop[0]);
				for (int i = 0; i < loop.size(); ++i) len[loop[i]] = loop.size();
			}
		}
		for (int i = 0; i < n; ++i) printf("%d ", len[i]);
		printf("\n");
		memset(len, 0, 4 * n);
	}
	return 0;
}