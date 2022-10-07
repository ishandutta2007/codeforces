#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=0;i<n;i++)putchar('a'+min(i%a,b-1));
		putchar('\n');
	}
	return 0;
}