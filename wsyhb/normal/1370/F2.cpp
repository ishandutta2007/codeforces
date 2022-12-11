#include<bits/stdc++.h>
using namespace std;
inline void query(vector<int> a)
{
	int c=a.size();
	cout<<"? "<<c;
	for(int i=0;i<c;++i)
		cout<<' '<<a[i];
	cout<<endl;
}
inline void answer(int u,int v)
{
	cout<<"! "<<u<<' '<<v<<endl;
	string res;
	cin>>res;
	if(res=="Incorrect")
		exit(0);
	assert(res=="Correct");
}
const int max_n=1e3+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
int dep[max_n],dfn[max_n][2],Time,id[max_n],fath[max_n];
void dfs(int x,int fa)
{
	dfn[x][0]=++Time;
	id[Time]=x;
	fath[x]=fa;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dep[y]=dep[x]+1;
			dfs(y,x);
		}
	}
	dfn[x][1]=Time;
}
vector<int> node[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		E=Time=0;
		for(int i=1;i<=n;++i)
		{
			Last[i]=0;
			node[i].clear();
		}
		for(int i=1;i<=n-1;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		vector<int> Full(n);
		for(int i=0;i<n;++i)
			Full[i]=i+1;
//		fprintf(stderr,"type 1\n");
		query(Full);
		int rt,dis;
		scanf("%d%d",&rt,&dis);
		if(rt==-1&&dis==-1)
			return 0;
		dep[rt]=0;
		dfs(rt,0);
		int L=(dis+1)>>1,R=0;
		for(int i=1;i<=n;++i)
		{
			if(dep[i]>=L&&dep[i]<=dis)
			{
				node[dep[i]].push_back(i);
				R=max(R,dep[i]); 
			}
		}
		int s=-1,f;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			vector<int> a;
			for(int i=mid;i<=R;++i)
				a.insert(a.end(),node[i].begin(),node[i].end());
//			fprintf(stderr,"type 2\n");
			query(a);
			int x,d;
			scanf("%d%d",&x,&d);
			if(x==-1&&d==-1)
				return 0;
			if(d==dis)
			{
				for(int i=L;i<=R;++i)
					node[i].clear();
				int R_new=0;
				for(int i=dfn[x][0]+1;i<=dfn[x][1];++i)
				{
					int y=id[i];
					if(dep[y]<=R)
					{
						node[dep[y]].push_back(y);
						R_new=max(R_new,dep[y]);
					}
				}
				s=x;
				if(!R_new)
					break;
				L=dep[x]+1,R=R_new;
			}
			else
			{
				for(int i=mid;i<=R;++i)
					node[i].clear();
				R=mid-1;
			}
		}
//		fprintf(stderr,"s=%d\n",s);
		if(dis-dep[s]==dep[s])
		{
			vector<int> a;
			for(int i=1;i<=n;++i)
			{
				if(dep[i]==dep[s]&&i!=s)
					a.push_back(i);
			}
			query(a);
			int x,d;
			scanf("%d%d",&x,&d);
			if(x==-1&&d==-1)
				return 0;
			assert(d==dis);
			f=x;
		}
		else if(dis-dep[s]>0)
		{
			int goal=dis-dep[s];
			assert(goal<dep[s]);
			int now=s;
			while(dep[now]!=goal)
				now=fath[now];
			vector<int> a;
			for(int i=1;i<=n;++i)
			{
				if(dep[i]==goal&&i!=now)
					a.push_back(i);
			}
//			fprintf(stderr,"type 4\n");
			query(a);
			int x,d;
			scanf("%d%d",&x,&d);
			if(x==-1&&d==-1)
				return 0;
			assert(d==dis);
			f=x;
		}
		else
			f=rt;
		answer(s,f);
	}
	return 0;
}