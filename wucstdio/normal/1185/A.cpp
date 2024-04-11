#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	int ans=0;
	ans+=max(0,d-(b-a));
	ans+=max(0,d-(c-b));
	printf("%d\n",ans);
	return 0;
}