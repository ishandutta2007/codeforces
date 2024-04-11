#include <stdio.h>
const int M=5000000;
int x[M],ls[M],rs[M],root,clock;
void Set(int &c, int num, int p, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(p<0) return;
	if(num&(1<<p)) Set(rs[c],num,p-1,val);
	else Set(ls[c],num,p-1,val);
}
int sol;
void Get(int c, int num, int p)
{
	if(p<0) return;
	if(num&(1<<p))
	{
		if(x[ls[c]]>0)
		{
			sol|=1<<p;
			Get(ls[c],num,p-1);
		}
		else Get(rs[c],num,p-1);
	}
	else
	{
		if(x[rs[c]]>0)
		{
			sol|=1<<p;
			Get(rs[c],num,p-1);
		}
		else Get(ls[c],num,p-1);
	}
}
int main()
{
	int n,x;
	char ch;
	scanf("%i",&n);
	Set(root,0,30,1);
	while(n--)
	{
		scanf("\n%c %i",&ch,&x);
		if(ch=='+') Set(root,x,30,1);
		if(ch=='-') Set(root,x,30,-1);
		if(ch=='?')
		{
			sol=0;
			Get(root,x,30);
			printf("%i\n",sol);
		}
	}
	return 0;
}