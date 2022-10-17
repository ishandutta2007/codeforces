#include<stdio.h>
int a[200020],c[200020],n,m,k,z;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int b=0,f=0;b<=n;--c[a[b++]])
	{
		while(f<n&&c[a[b]]+k>=f-b)
			++c[a[f++]];
		if(z<c[a[b]])
			z=c[a[b]];
	}
	printf("%d\n",z);
}