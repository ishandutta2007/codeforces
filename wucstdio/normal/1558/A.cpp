#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,ans[200005],top;
void solve(int x)
{
	for(int i=abs(a-x);i<=a+b-abs(b-x);i+=2)ans[++top]=i;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		top=0;
		if((a+b)&1)
		{
			solve((a+b)>>1);
			solve((a+b+1)>>1);
		}
		else solve((a+b)>>1);
		printf("%d\n",top);
		sort(ans+1,ans+top+1);
		for(int i=1;i<=top;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}