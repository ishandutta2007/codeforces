#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d",&n);
	if(n % 4 >= 2)
		return puts("NO"), 0;
	puts("YES");
	for(int i = 1; i < n; i += 2) {
		for(int j = i + 2; j < n; j += 2)
			printf("%d %d\n", i, j),printf("%d %d\n", i + 1, j + 1),
			printf("%d %d\n", i, j + 1),printf("%d %d\n", i + 1, j);
		if(n % 4)
		printf("%d %d\n", i, n);
		printf("%d %d\n", i, i + 1);
		if(n % 4)
		printf("%d %d\n", i + 1, n);
	}
}