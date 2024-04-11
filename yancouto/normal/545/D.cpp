#include <cstdio>
#include <algorithm>

typedef unsigned long long ull;

int main() {
	int n;
	ull ts[100003];
	scanf("%d", &n); int a;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		ts[i] = a;
	}
	std::sort(ts, ts + n);
	ull total = 0; int happy = 0;
	for(int i = 0; i < n; i++)
		if(total <= ts[i]) {
			happy++;
			total += ts[i];
		}
	printf("%d\n", happy);
}