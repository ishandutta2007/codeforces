#include <cstdio>
#include <algorithm>
#define MAXN 1005

int n;
int a[MAXN];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	std::nth_element(a+1,a+(n+1>>1),a+1+n);
	return printf("%d\n",a[n+1>>1])&0;
}