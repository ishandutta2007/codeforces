#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a[105];
bool flag[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			flag[x]=1;
		}
		for(int i=1;i<=n;)
		{
			int j=i;
			while(flag[j])j++;
			sort(a+i,a+j+1);
			i=j+1;
		}
		bool f=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				printf("NO\n");
				f=0;
				break;
			}
		}
		if(f)puts("YES");
	}
	return 0;
}