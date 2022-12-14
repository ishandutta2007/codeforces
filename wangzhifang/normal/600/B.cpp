#include <cstdio>
#include <algorithm>
using namespace std;
#define max_n 200000
int a[max_n];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)
		scanf("%d",a+i);
	sort(a,a+n);
	for(int x; m; --m){
		scanf("%d",&x);
		printf("%d ",upper_bound(a,a+n,x)-a);
	}
	return 0;
}