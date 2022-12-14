#include <cstdio>
#include <algorithm>
int f[17]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
int b[1001];
int main()
{
	for(int i=1;i<=16;i++)
	{
		b[f[i]]=1;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			putchar('O');
		}else
		{
			putchar('o');
		}
	}
	puts("");
	return 0;
}