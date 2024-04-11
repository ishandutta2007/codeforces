#include<stdio.h>
int O(int x,int y,char c)
{
	if(c=='^')
		return x^y;
	else if(c=='&')
		return x&y;
	else if(c=='|')
		return x|y;
}
int G()
{
	char c;
	scanf(" %c",&c);
	if(c=='0')
		return 1;
	else if(c=='1')
		return 8;
	else if(c=='?')
		return 6;
	int x=G();
	scanf(" %c",&c);
	int y=G();
	int z=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(x>>i&1&&y>>j&1)
				z|=1<<O(i,j,c);
	scanf(" %c",&c);
	return z;
}
int main()
{
	scanf("%*d");
	puts(G()&6?"YES":"NO");
}