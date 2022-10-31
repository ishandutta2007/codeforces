#include <cstdio>
#include <algorithm>

int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>b) std::swap(a,b);
	int res=1;
	for(int i=1;i<=a;i++) res*=i;
	printf("%d\n",res);
	return 0;
}