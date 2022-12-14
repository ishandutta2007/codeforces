#include<cstdio>
#include<algorithm>

using namespace std;

int x,y,z;

int main()
{
	int n,xx;
	scanf("%d%d",&n,&xx);
	for(int i=0;i<n;i++)
	{
		int in;
		scanf("%d",&in);
		if(in<xx) x++;
		if(in==xx) z++;
		if(in>xx) y++;
	}
	int ans;
	if(x==y)
	{
		if(z==0) ans=1;
		else ans=0;
	}
	if(x<y)
	{
		ans=max(0,y-x-z);
	}
	if(x>y)
	{
		ans=max(0,x-y+1-z);
	}
	printf("%d\n",ans);
	return 0;
}