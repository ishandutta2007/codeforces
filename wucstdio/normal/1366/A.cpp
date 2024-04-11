#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		if(a*2<b)printf("%d\n",a);
		else printf("%d\n",b-a+(a-(b-a))/3*2+((a-(b-a))%3==2));
	}
	return 0;
}