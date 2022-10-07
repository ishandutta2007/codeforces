#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==0&&b==0)
		{
			for(int i=1;i<=c+1;i++)
			  putchar('1');
			putchar('\n');
			continue;
		}
		if(b==0&&c==0)
		{
			for(int i=1;i<=a+1;i++)
			  putchar('0');
			putchar('\n');
			continue;
		}
		putchar('0');
		for(int i=1;i<=a;i++)putchar('0');
		b--;
		putchar('1');
		for(int i=1;i<=c;i++)putchar('1');
		int last=1;
		while(b--)
		{
			last^=1;
			printf("%d",last);
		}
		putchar('\n');
	}
	return 0;
}