#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,a[300005],b[300005],saa[300005],sab[300005],tot,x[3000005],y[3000050],d[3000005];
queue<pair<int,int> >q;
bool cmpa(int x,int y)
{
	return a[x]<a[y];
}
bool cmpb(int x,int y)
{
	return b[x]<b[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)saa[i]=sab[i]=i;
	sort(saa+1,saa+n+1,cmpa);
	sort(sab+1,sab+n+1,cmpb);
	for(int i=1;i<=n;i++)
	{
		if(a[saa[i]]==b[sab[i]])continue;
		if(a[saa[i]]>b[sab[i]])
		{
			int val=a[saa[i]]-b[sab[i]];
			while(val&&!q.empty())
			{
				int node=q.front().second;
				int v=q.front().first;
				q.pop();
				if(v<=val)
				{
					val-=v;
					x[++tot]=node,y[tot]=saa[i];
					d[tot]=v;
				}
				else
				{
					v-=val;
					x[++tot]=node,y[tot]=saa[i];
					d[tot]=val;
					val=0;
					q.push(make_pair(v,node));
				}
			}
			if(val)
			{
				printf("NO\n");
				return 0;
			}
		}
		else q.push(make_pair(b[sab[i]]-a[saa[i]],saa[i]));
	}
	if(!q.empty())
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d %d\n",x[i],y[i],d[i]);
	return 0;
}