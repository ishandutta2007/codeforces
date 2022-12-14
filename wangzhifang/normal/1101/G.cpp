#include <cstdio>
#define max_bit 30
using namespace std;
int a[max_bit];
int main(){
	int n,sum,sumall,ans;
	scanf("%d",&n),sum=0,sumall=0,ans=0;
	for(int i=0,x,*tmp; ++i<=n; ){
		scanf("%d",&x);
		sum^=x,sumall^=x;
		while(sum)
			(*(tmp=a+__builtin_ctz(sum)))?(sum^=*tmp):(*tmp=sum,++ans);
	}
	if(sumall)
		printf("%d\n",ans);
	else
		puts("-1");
	return 0;
}