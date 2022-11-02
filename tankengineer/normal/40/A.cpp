#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int dis = x * x + y * y, flag = x * y, z = 0;
	while (z * z < dis) {
		++z;
	}
	if (flag == 0 || z * z == dis) {
		puts("black");
	} else {
		puts(((z & 1) ^ (flag > 0) ^ 1) ? "black" : "white");
	}
	return 0;
}