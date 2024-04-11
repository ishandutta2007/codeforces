#include<stdio.h>
int P(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}
int F(int x,int k)
{
	if(x<k||P(k))
		return 0;
	int _=x/=k;
	for(int i=2;i<k&&i<=x;i++)
		_-=F(x,i);
	return _;
}
int main()
{
	int l,r,k;
	scanf("%d %d %d",&l,&r,&k);
	printf("%d",F(r,k)-F(l-1,k));
	return 0;
}