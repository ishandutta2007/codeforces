#include <cstdio>
#include <algorithm>
using namespace std;
#define max_n 100000
int a[max_n+1];
int main(){
	int n,p,ans1=0,ans2=2147483647;
	scanf("%d%d",&n,&p);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i){
		ans1=max(ans1,a[i]-i+1);
		if(i>=p)
			ans2=min(ans2,a[i]-i+p);
	}
	printf("%d\n",max(ans2-ans1,0));
	for(int i=ans1; i<ans2; ++i)
		printf("%d ",i);
	return 0;
}