#include<stdio.h>
int a[100020],b[100020];
int x[10000020],y[10000020];
int p[10000020];
int n,m;
void div(int n,int *a,int *c)
{
	for(int i=0;i<n;i++)
		for(int j=a[i];j>1;j/=p[j])
			c[p[j]]++;
}
void pt(int n,int *a,int *c)
{
	for(int i=0;i<n;i++)
	{
		int _=1;
		for(int j=a[i];j>1;j/=p[j])
			if(c[p[j]])
				c[p[j]]--;
			else
				_*=p[j];
		printf("%d%c",_,i<n-1?' ':'\n');
	}
}
int main()
{
	for(int i=2;i<10000020;i++)
		if(!p[i])
			for(int j=i;j<10000020;j+=i)
				p[j]=i;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<m;i++)
		scanf("%d",b+i);
	printf("%d %d\n",n,m);
	div(n,a,x);
	div(m,b,y);
	pt(n,a,y);
	pt(m,b,x);
	return 0;
}