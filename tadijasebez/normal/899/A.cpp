#include <stdio.h>

int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}

int main()
{
	int cnt1=0,cnt2=0,n,x,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x==1) cnt1++;
		else cnt2++;
	}
	int sol;
	if(cnt2>cnt1) sol=cnt1;
	else sol=cnt2+(cnt1-cnt2)/3;
	printf("%i\n",sol);
	return 0;
}