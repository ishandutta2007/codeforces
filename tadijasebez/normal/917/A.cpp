#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5050;
int c,d;
char ch[N];
int Calc(int b, int e)
{
	c=0,d=0;
	int ret=0,i;
	for(i=b;i<=e;i++)
	{
		if(ch[i]=='(') c++;
		if(ch[i]==')')
		{
			if(c) c--;
			else
			{
				if(d>0) d--,c++;
				else return ret;
			}
		}
		if(ch[i]=='?')
		{
			if(c) c--,d++;
			else c++;
		}
		if(c==0)
		{
			ret++;
			//printf("%i %i\n",b,i);
		}
	}
	return ret;
}
int main()
{
	int n,i,sol=0;
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i++) sol+=Calc(i,n);
	printf("%i\n",sol);
	return 0;
}