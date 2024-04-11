#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[100005];
bool flag[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			flag[i]=0;
		}
		for(int i=2;i<=n;i++)
		  if(p[i]==p[i-1]+1)
		    flag[i]=1;
		int last=0;
		bool res=1;
		for(int i=n;i>=1;i--)
		{
			if(!flag[i])
			{
				if(last>p[i])res=0;
				last=p[i];
			}
		}
		puts(res?"Yes":"No");
	}
	return 0;
}