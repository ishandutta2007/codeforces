#include <stdio.h>
int a[6],sum,tr;
bool Try(int p, int c)
{
	tr+=a[p];
	c++;
	if(c==3)
	{
		if(tr*2==sum) return true;
		else{ tr-=a[p];return false;}
	}
	for(int i=p+1;i<6;i++)
	{
		if(Try(i,c)) return true;
	}
	tr-=a[p];
	return false;
}
int main()
{
	int i;
	for(i=0;i<6;i++) scanf("%i",&a[i]),sum+=a[i];
	if(Try(0,0) || Try(1,0) || Try(2,0) || Try(3,0) || Try(4,0) || Try(5,0)) printf("YES\n");
	else printf("NO\n");
	return 0;
}