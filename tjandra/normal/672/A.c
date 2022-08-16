#include<stdio.h>
typedef unsigned u;
u F(u i,u j)
{
	u k=1;
	while(k<=i)k*=10;
	for(k/=10;--j;k/=10);
	if(!k)return -1;
	return i/k%10;
}
int main()
{
	u n,i=1,j=1;
	for(scanf("%u",&n);--n;)
	if(F(i,++j)==-1u){++i;j=1;}
	printf("%u\n",F(i,j));
	return 0;
}