#include<stdio.h>
long long k;
int x[100020];
int y[100020];
int i,n,px,py;
int main()
{
	scanf("%d %I64d %d %d",&n,&k,&px,&py);
	for(i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	for(k%=2*n,i=0;i<k;i++)
	{
		px=2*x[i%n]-px;
		py=2*y[i%n]-py;
	}
	printf("%d %d\n",px,py);
	return 0;
}