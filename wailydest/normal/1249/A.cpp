#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		bool a[100] = {0};
		int val;
		bool two = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &val);
			--val;
			if (val > 0 && a[val - 1]) two = 1;
			if (val < 99 && a[val + 1]) two = 1;
			a[val] = 1;
		}
		printf("%d\n", (int)two + 1);
	}
}