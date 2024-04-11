#include <cstdio>
#define max_n 100
#define INF 2147483647
using namespace std;
int a[max_n+1];
int main(){
	int n,sum,num,mna;
	scanf("%d",&n),sum=num=0,mna=INF;
	for(int i=0,m=2*n-1; ++i<=m; a[i]<0?(sum-=a[i],++num,-a[i]<mna&&(mna=-a[i])):(sum+=a[i],a[i]<mna&&(mna=a[i])))
		scanf("%d",a+i);
	if((n&1)||((num&1)==0))
		printf("%d\n",sum);
	else
		printf("%d\n",sum-2*mna);
	return 0;
}