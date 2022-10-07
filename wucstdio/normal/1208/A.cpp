#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d%d",&a,&b,&n);
		if(n%3==0)printf("%d\n",a);
		if(n%3==1)printf("%d\n",b);
		if(n%3==2)printf("%d\n",a^b);
	}
	return 0;
}