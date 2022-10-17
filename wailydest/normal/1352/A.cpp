#include <cstdio>
#include <vector>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int i = 1;
		vector<int> x;
		while (n) {
			if (n % 10) {
				x.push_back(n % 10 * i);
			}
			n /= 10;
			i *= 10;
		}
		printf("%d\n", x.size());
		for (int i = 0; i < x.size(); ++i) printf("%d ", x[i]);
		printf("\n");
	}
	return 0;
}