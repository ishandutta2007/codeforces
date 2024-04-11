#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct edge
{
	int y,v;
	edge(int _y=0,int _v=0){y=_y,v=_v;}
	bool operator<(const edge& b)const
	{
		return v<b.v||(v==b.v&&y<b.y);
	}
};
vector<edge>e[N],delay[N];
int tmp[N],mi[N];
bool used[N];
int main()
{
	int n,m,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].push_back(edge(y,v));
		e[y].push_back(edge(x,v));
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
			scanf("%d",&tmp[j]);
		int jj;
		for(int j=0;j<k;j+=jj)
		{
			for(jj=1;j+jj<k&&tmp[j+jj]==tmp[j+jj-1]+1;jj++);
				delay[i].push_back(edge(tmp[j],tmp[j+jj-1]));
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		mi[i]=1010000000;
	q.push(1);
	mi[1]=0;
	while(q.size())
	{
		int now=q.front();
		q.pop();
		used[now]=0;
		int of=lower_bound(delay[now].begin(),delay[now].end(),edge(-1,mi[now]))-delay[now].begin();
		int st;
		if(of==delay[now].size())
			st=mi[now];
		else
		{
			if(mi[now]>=delay[now][of].y&&mi[now]<=delay[now][of].v)
				st=delay[now][of].v+1;
			else
				st=mi[now];
		}
		for(int i=0;i<e[now].size();i++)
		{
			if(mi[e[now][i].y]>st+e[now][i].v)
			{
				mi[e[now][i].y]=st+e[now][i].v;
				if(!used[e[now][i].y])
				{
					used[e[now][i].y]=1;
					q.push(e[now][i].y);
				} 
			}
		}
	}
	if(mi[n]==1010000000)
		printf("-1\n");
	else
		printf("%d\n",mi[n]);
	return 0;
}