#include <cstdio>
#include <algorithm>
#include <cstring>
int step,now,n;
int main() {
	scanf("%d",&n);
	step = 0;
	while (n > 0) {
		++step;
		now += step; 
		n -= now;
		if (n < 0) --step;
	}
	printf("%d\n",step);
}