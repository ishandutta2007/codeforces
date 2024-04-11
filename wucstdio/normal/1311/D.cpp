#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		int v1=0,v2=0,v3=0,ans=2147483647;
		for(int i=1;i<=11000;i++)
		  for(int j=i;j<=11000;j+=i)
		    for(int k=j;k<=11000;k+=j)
		      if(abs(a-i)+abs(b-j)+abs(c-k)<ans)
		        ans=abs(a-i)+abs(b-j)+abs(c-k),v1=i,v2=j,v3=k;
		printf("%d\n",ans);
		printf("%d %d %d\n",v1,v2,v3);
	}
	return 0;
}