#include<cstdio>
#include<cstring>
using namespace std;

char a[105], b[105], c[105];

int main() {
	scanf("%s%s", a, b);
	int l = strlen(a);
	for (int i = 0; i < l; ++i) {
		c[i] = (int)(a[i] != b[i]) + '0';
	}
	printf("%s\n", c);
	return 0;
}