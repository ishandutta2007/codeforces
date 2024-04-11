#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		if(n%3==0||n%3==2)
		{
			for(int i=1;i<n;i++)putchar('2');
			putchar('3');
			putchar('\n');
		}
		else if(n%3==1)
		{
			for(int i=1;i<n-1;i++)putchar('2');
			putchar('3'),putchar('3');
			putchar('\n');
		}
	}
}