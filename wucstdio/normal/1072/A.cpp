#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int w,h,k,ans;
int main()
{
	scanf("%d%d%d",&w,&h,&k);
	for(int i=1;i<=k;i++)
	{
		ans+=2*(w-1)+2*(h-1);
		h-=4,w-=4;
	}
	printf("%d\n",ans);
	return 0;
}