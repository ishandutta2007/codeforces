#include <cstdio>
#include <algorithm>

using namespace std;

int a,b;

int main() {
	scanf("%d%d",&a,&b);
	if (b>a) return printf("-1\n"),0;
	int n = a/b;
	if (n%2==0) n-=1;
	int res = n*b;
	int diff = a-res;
	printf("%1.9f\n",b+1.*diff/(n+1));

	return 0;
}