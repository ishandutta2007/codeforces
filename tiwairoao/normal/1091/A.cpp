#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int y, b, r;
	scanf("%d%d%d", &y, &b, &r);
	int ans = min(min(y, b-1), r-2)*3 + 3;
	printf("%d\n", ans);
}