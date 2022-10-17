#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

const int N = 1000;
int n;
int a[N];

bool test() 
{
	for (int i = 1; i < n; ++i) if (a[i] < a[i - 1]) return false;
	return true;
}

int get() 
{
	bool c[N] = {0};
	for (int i = 0; i < n; ++i) if (a[i] != n) c[a[i]] = true;
	int i = 0;
	while (i < n && c[i]) ++i;
	return i;
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		vector<int> op;
		while (!test()) {
			int mex = get();
			if (mex == n) {
				for (int i = 0; i < n; ++i) if (a[i] != i) {
					op.push_back(i);
					a[i] = mex;
					break;
				}
			}
			else {
				op.push_back(mex);
				a[mex] = mex;
			}
		}
		assert(op.size() <= n * 2);
		printf("%d\n", op.size());
		for (int i = 0; i < op.size(); ++i) printf("%d ", op[i] + 1);
		printf("\n");
	}
	return 0;
}