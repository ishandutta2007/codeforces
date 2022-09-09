#include <stdio.h>
const int N=100050;
const int M=1050;
int a[N],b[M],c[M],x;
void Update()
{
	int i;
	for(i=0;i<M;i++) b[i]=c[i],c[i]=0;
	int sz=0;
	for(i=0;i<M;i++)
	{
		if(sz&1)
		{
			c[i]+=(b[i]+1)/2;
			c[i^x]+=b[i]/2;
		}
		else
		{
			c[i]+=b[i]/2;
			c[i^x]+=(b[i]+1)/2;
		}
		sz+=b[i];
	}
}
int main()
{
	int n,k,i;
	scanf("%i %i %i",&n,&k,&x);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),c[a[i]]++;
	while(k--) Update();
	int Min=-1,Max=-1;
	for(i=0;i<M;i++)
	{
		if(!(~Min) && c[i]) Min=i;
		if(c[i]) Max=i;
	}
	printf("%i %i\n",Max,Min);
	return 0;
}