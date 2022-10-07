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
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if((a+b)&1)
		{
			if(b+c&&a+d)printf("Ya Ya Tidak Tidak\n");
			else if(b+c)printf("Tidak Ya Tidak Tidak\n");
			else printf("Ya Tidak Tidak Tidak\n");
		}
		else
		{
			if(b+c&&a+d)printf("Tidak Tidak Ya Ya\n");
			else if(b+c)printf("Tidak Tidak Ya Tidak\n");
			else printf("Tidak Tidak Tidak Ya\n");
		}
	}
	return 0;
}