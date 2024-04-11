#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	long long sum = 0, ans = 0;
	int last = -1;
	map<long long, int> mem;
	mem[sum] = -1;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		sum += a;
		if (mem.count(sum)) {
			last = max(last, mem[sum] + 1);
		}
		mem[sum] = i;
		ans += i - last;
	}
	printf("%I64d\n", ans);
	return 0;
}