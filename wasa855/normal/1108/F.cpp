#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int from;
	int to;
	int dis;
};
int fa[200005];
int find(int k)
{
    int i=k;
    while(fa[i]!=i)
    {
    	i=fa[i];
    }
    int j;
    while(fa[k]!=k)
    {
        j=k;
        k=fa[k];
        fa[j]=i;
    }
    return i;
}
Edge edge[200005];
bool cmp(Edge x,Edge y)
{
	return x.dis<y.dis;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].dis);
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int cnt=1;
	int ans=0;
	for(int i=1;i<=m;i=cnt)
	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",find(j));
//		}
//		cout<<"\n";
		while(cnt<=m&&edge[i].dis==edge[cnt].dis)
		{
			cnt++;
		}
		int dat=cnt-i;
		for(int j=i;j<cnt;j++)
		{
			if(find(edge[j].from)==find(edge[j].to))
			{
				dat--;
			}
		}
		for(int j=i;j<cnt;j++)
		{
			if(find(edge[j].from)!=find(edge[j].to))
			{
				dat--;
				fa[find(edge[j].from)]=find(edge[j].to);
			}
		}
		ans+=dat;
//		printf("%d %d %d\n",i,cnt,dat);
	}
	cout<<ans<<endl;
	return 0;
}