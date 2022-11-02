#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int main() {
	int b, k, ret = 0; scanf("%d%d", &b, &k);
	for(int i=1;i<=k;i++) {
		int x; scanf("%d", &x);
		ret = (ret*b%2 + x)%2;
	}
	puts(ret ? "odd" : "even");
}