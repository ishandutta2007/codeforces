#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],weight[max_n<<1],cost[max_n<<1],e;
inline void add_edge(int x,int y,int w,int c)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e,weight[e]=w,cost[e]=c;
	End[++e]=x,Next[e]=Last[y],Last[y]=e,weight[e]=w,cost[e]=c;
}
int cnt_leaf[max_n];
long long sum;
priority_queue<long long> q1,q2;
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			sum+=1ll*cnt_leaf[y]*weight[i];
			priority_queue<long long> *q=cost[i]==1?&q1:&q2;
			int w=weight[i];
			while(w)
			{
//				fprintf(stderr,"cost=%d weight=%d\n",cost[i],w-(w>>1));
				q->push(1ll*cnt_leaf[y]*(w-(w>>1)));
				w>>=1;
			}
			cnt_leaf[x]+=cnt_leaf[y];
		}
	}
	if(!cnt_leaf[x])
		++cnt_leaf[x];
//	fprintf(stderr,"x=%d cnt_leaf[x]=%d\n",x,cnt_leaf[x]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long S;
		scanf("%d%lld",&n,&S);
//		fprintf(stderr,"S=%lld\n",S);
		for(int i=1;i<=n;++i)	
			Last[i]=cnt_leaf[i]=0;
		e=0;
		sum=0;
		while(!q1.empty())
			q1.pop();
		while(!q2.empty())
			q2.pop();
		for(int i=1;i<=n-1;++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w,1);
		}
		dfs(1,0);
		/*
		priority_queue<long long> now=q1;
		fprintf(stderr,"cost=1:\n");
		while(!now.empty())
		{
			fprintf(stderr,"%lld\n",now.top());
			now.pop();
		}
		now=q2;
		fprintf(stderr,"cost=2:\n");
		while(!now.empty())
		{
			fprintf(stderr,"%lld\n",now.top());
			now.pop();
		}
		fprintf(stderr,"sum=%lld\n",sum);
		*/
		vector<long long> s1(1),s2(1);
		while(!q1.empty())
		{
			s1.push_back(s1.back()+q1.top());
			q1.pop();
		}
		while(!q2.empty())
		{
			s2.push_back(s2.back()+q2.top());
			q2.pop();
		}
		int ans=1e9;
		for(int i=0,j=(int)s2.size()-1;i<int(s1.size());++i)
		{
			while(j>0&&s1[i]+s2[j-1]>=sum-S)
				--j;
			if(s1[i]+s2[j]>=sum-S)
				ans=min(ans,i+2*j);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1
*/