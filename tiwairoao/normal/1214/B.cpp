#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int b, g, n;
	scanf("%d%d%d", &b, &g, &n);
	int lb = max(0, n - g), rb = min(b, n);
	printf("%d\n", rb - lb + 1);
}