#include <stdio.h>
const int N=100050;
int main()
{
	int sum=0,n,i,x,d;
	scanf("%i %i",&n,&d);
	sum=(n-1)*10;int jk=(n-1)*2;
	while(n--) scanf("%i",&x),sum+=x;
	if(sum>d) return printf("-1\n"),0;
	jk+=(d-sum)/5;
	printf("%i\n",jk);
	return 0;
}