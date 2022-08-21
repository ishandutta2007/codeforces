#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,m,sn=0;
char sb[2333333];
void end1()
{
	while(n&&m&&(n>=m||m>=2))
	{
		if(n>=m) --n, --m, sb[sn++]='0', sb[sn++]='1';
		else n--, m-=2, sb[sn++]='1', sb[sn++]='0', sb[sn++]='1';
	}
}
void end0()
{
	while(n&&m&&(n>=m||m>=2))
	{
		if(n>=m) --n, --m, sb[sn++]='1', sb[sn++]='0';
		else n--, m-=2, sb[sn++]='1', sb[sn++]='1', sb[sn++]='0';
	}
}
bool sbs1(int n,int m)
{
	while(n&&m&&(n>=m||m>=2))
	{
		if(n>=m) --n, --m;
		else n--, m-=2;
	}
	if(n==2&&m==1) end1(), sb[sn++]='0', sb[sn++]='1', sb[sn++]='0';
	else if(n==1&&m==1) end1(), sb[sn++]='0', sb[sn++]='1';
	else if(n==0&&m==1) end0(), sb[sn++]='1';
	else if(m<=2&&n==0)
	{
		end0(); while(m--) sb[sn++]='1';
	}
	else if(n==1&&m==0)
	{
		end1(); sb[sn++]='0';
	}
	else return 0;
	return 1;
}
bool sbs2(int n,int m)
{
	while(n&&m) --n, --m;
	if(n==2&&m==1) end1(), sb[sn++]='0', sb[sn++]='1', sb[sn++]='0';
	else if(n==1&&m==1) end1(), sb[sn++]='0', sb[sn++]='1';
	else if(n==0&&m==1) end0(), sb[sn++]='1';
	else if(m<=2&&n==0)
	{
		end0(); while(m--) sb[sn++]='1';
	}
	else if(n==1&&m==0)
	{
		end1(); sb[sn++]='0';
	}
	else return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	sn=0;
	if(sbs1(n,m)) {sb[sn]=0; puts(sb); return 0;}
	sn=0;
	if(sbs2(n,m)) {sb[sn]=0; puts(sb); return 0;}
	puts("-1");
}