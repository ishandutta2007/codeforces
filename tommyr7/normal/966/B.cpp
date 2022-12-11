#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n,x1,x2;
pair<int,int> w[Maxn];
bool flag1[Maxn],flag2[Maxn];
bool g1[Maxn],g2[Maxn];
void process(int x,int y)
{
	printf("Yes\n");
	int len1=((x1+w[x].first-1)/w[x].first);
	int len2=((x2+w[y].first-1)/w[y].first);
	printf("%d %d\n",len1,len2);
	for (int i=1;i<=len1;i++)
		printf("%d ",w[x+i-1].second);
	printf("\n");
	for (int i=1;i<=len2;i++)
		printf("%d ",w[y+i-1].second);
	printf("\n");
}
int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	for (int i=1;i<=n;i++)
	{
		w[i].second=i;
		scanf("%d",&w[i].first);
	}
	sort(w+1,w+n+1);
	g1[n+1]=false,g2[n+1]=false;
	for (int i=1;i<=n;i++)
	{
		if ((x1+w[i].first-1)/w[i].first<=n-i+1) flag1[i]=true; else flag1[i]=false;
		if ((x2+w[i].first-1)/w[i].first<=n-i+1) flag2[i]=true; else flag2[i]=false;
		g1[i]=g1[i+1]|flag1[i];
		g2[i]=g2[i+1]|flag2[i];
	}
	for (int i=1;i<n;i++)
	{
		if (flag1[i])
		{
			int t=((x1+w[i].first-1)/w[i].first)+i;
			if (g2[t])
			{
				process(i,t);
				return 0;
			}
		}
		if (flag2[i])
		{
			int t=((x2+w[i].first-1)/w[i].first)+i;
			if (g1[t])
			{
				process(t,i);
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}