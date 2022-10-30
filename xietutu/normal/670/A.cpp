#include <cstdio>
#include <algorithm>
using namespace std;
int n, minv, maxv;
int main() {
	scanf("%d", &n);
	if (n <= 2) maxv = n;
	else {
		maxv = 2;
		maxv += (n - 2) / 7 * 2;
		if ((n - 2) % 7 == 6) ++maxv;
	}
	
	if (n <= 5) minv = 0;
	else {
		minv = (n - 5) / 7 * 2;
		minv += min((n - 5) % 7, 2); 
	}
	printf("%d %d\n", minv, maxv);
}