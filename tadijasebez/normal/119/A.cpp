#include <stdio.h>
int nzd(int a, int b)
{
	int q,r,tmp;
	if(a<b) 
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	q=a/b;
	r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		q=a/b;
		r=a%b;
	}
	return b;
}
int main()
{
	int a,b,n,i;
	scanf("%i%i%i",&a,&b,&n);
	i=1;
	while(n>0)
	{
		if(i==1)
		{
			n-=nzd(a,n);
			i=0;
		}
		else if(i==0)
		{
			n-=nzd(b,n);
			i=1;
		}
	}
	printf("%i",i);
	return 0;
}