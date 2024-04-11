#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to;
	int nxt;
};
Edge edge[200005];
int first[200005];
int dfn[200005];
int num[200005];
int son[200005];
int cnt;
int ss;
void dfs(int now)
{
//	printf("%d ",now);
	cnt++;
	dfn[now]=cnt;
	num[cnt]=now;
	vector<int> v;
	int l=0;
	son[now]=1;
	for(int i=first[now];i!=0;i=edge[i].nxt)
	{
		l++;
		v.push_back(edge[i].to);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<l;i++)
	{
		dfs(v[i]);
		son[now]+=son[v[i]];
	}
}
void add(int u,int v)
{
	ss++;
	edge[ss].to=v;
	edge[ss].nxt=first[u];
	first[u]=ss;
}
int main()
{
	int n,q;
	cin>>n>>q;
	int t;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&t);
//		printf("%d %d\n",t,i);
		add(t,i);
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d : ",i);
//		for(int j=first[i];j!=0;j=edge[j].nxt)
//		{
//			printf("%d ",edge[j].to);
//		}
//		cout<<"\n";
//	}
	dfs(1);
//	cout<<"\n\n";
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",son[i]);
//	}
//	cout<<"\n";
	int u,v;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&u,&v);
		if(son[u]<v)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",num[dfn[u]+v-1]);
		}
	}
	return 0;
}