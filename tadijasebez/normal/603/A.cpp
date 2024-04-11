#include <stdio.h>
const int N=100050;
char ch[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",ch+1);
	int tmp=0,Best=0,sol=0,ans=0;
	for(i=1;i<=n;i++)
	{
		if(ch[i]!=ch[i-1])
		{
			tmp=1;
			sol++;
		}
		else tmp++;
		Best=max(Best,tmp);
		if(tmp==2) ans++;
	}
	if(Best>2) sol+=2;
	else if(Best==2 && ans>1) sol+=2;
	else if(Best==2) sol++;
	printf("%i\n",sol);
	return 0;
}