#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[4005],top;
bool f[4005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		int v=0,cur=0;
		for(int i=1;i<=2*n;i++)
		{
			int x;
			scanf("%d",&x);
			if(v<x)
			{
				if(cur)a[++top]=cur;
				v=x;
				cur=1;
			}
			else cur++;
		}
		for(int i=0;i<=2*n;i++)f[i]=0;
		f[0]=1;
		for(int i=1;i<=top;i++)
		{
			for(int j=2*n;j>=a[i];j--)
			  f[j]|=f[j-a[i]];
		}
		if(f[n])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}