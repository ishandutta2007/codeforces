#include <stdio.h>
const int N=1<<17;
const int M=N*2;
int x[M],y[M];
int max(int a, int b){ return a>b?a:b;}
void Set(int i, int k)
{
	i+=N;
	x[i]=k;
	y[i]=(k==1);
	for(i>>=1;i;i>>=1)
	{
		x[i]=x[i<<1]+x[i<<1|1];
		y[i]=max(y[i<<1|1],x[i<<1|1]+y[i<<1]);
	}
}
int Get()
{
	int s=0,i;
	for(i=1;i<N;)
	{
		if(y[i<<1|1]+s>0) i=i<<1|1;
		else s+=x[i<<1|1],i<<=1;
	}
	return i-N;
}
int a[N];
int main()
{
	int n,i,p,t;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i",&p,&t);
		if(t==1) scanf("%i",&a[p]),Set(p,1);
		else Set(p,-1);
		int sol=Get();
		if(!a[sol]) printf("-1\n");
		else printf("%i\n",a[sol]);
	}
	return 0;
}