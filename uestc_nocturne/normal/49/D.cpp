#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1200],n;
int cal(int x)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
	{
		if((a[i]+i)%2!=x)
		sum++;
	}
	return sum;
}
int main()
{
	int i,ans0,ans1,ans;
	char ch[1200];
	while(~scanf("%d",&n))
	{
		scanf("%s",ch);
		for(i=1;i<=n;i++)
		a[i]=(int)(ch[i-1]-'0');
		ans1=cal(1);
		ans0=cal(0);
		ans=min(ans0,ans1);
		printf("%d\n",ans);
	}
}