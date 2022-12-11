#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
vector<int> val[max_n];
int id[max_n],tot,sz[max_n];
inline bool cmp(int x,int y)
{
	return val[x].size()<val[y].size();
}
const int max_N=12e5+5;
int A[max_N],B[max_N],N,pos[max_N];
struct Triplet
{
	int x,y,v;
	inline Triplet(int X,int Y,int V)
	{
		x=X,y=Y,v=V;
	}
};
inline bool operator < (const Triplet &a,const Triplet &b)
{
	return a.v<b.v;
}
priority_queue<Triplet> q[max_N];
typedef pair<long long,int> P;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		map<int,int> cnt;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			++cnt[a];
		}
		for(int i=0;i<=n;++i)
			val[i].clear();
		for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
			val[it->second].push_back(it->first);
		typedef pair<int,int> Pi;
		map<Pi,bool> vis;
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vis[Pi(x,y)]=vis[Pi(y,x)]=true;
		}
		tot=0;
		for(int i=1;i<=n;++i)
		{
			if(!val[i].empty())
			{
				id[++tot]=i;
				sz[i]=val[i].size();
				reverse(val[i].begin(),val[i].end());
			}
		}
		sort(id+1,id+tot+1,cmp);
		N=0;
		priority_queue<P> glob;
		for(int i=1;i<=tot;++i)
			for(int j=i;j<=tot;++j)
			{
				int a=id[i],b=id[j];
				A[++N]=a,B[N]=b,pos[N]=1;
				q[N].push(Triplet(0,0,val[a][0]+val[b][0]));
				glob.push(P(1ll*(val[a][0]+val[b][0])*(a+b),N));
			}
		while(1)
		{
			assert(!glob.empty());
			int x=glob.top().second;
			int a=A[x],b=B[x];
			int X=q[x].top().x,Y=q[x].top().y;
			int c=val[a][X],d=val[b][Y];
			if(c!=d&&!vis[Pi(c,d)])
			{
				printf("%lld\n",glob.top().first);
				break;
			}
			glob.pop(),q[x].pop();
			if(Y+1<sz[b])
				q[x].push(Triplet(X,Y+1,val[a][X]+val[b][Y+1]));
			if(pos[x]<sz[a])
			{
				if(q[x].empty()||val[a][pos[x]]+val[b][0]>q[x].top().v)
				{
					q[x].push(Triplet(pos[x],0,val[a][pos[x]]+val[b][0]));
					++pos[x];
				}
			}
			if(!q[x].empty())
				glob.push(P(1ll*q[x].top().v*(a+b),x));
		}
		for(int i=1;i<=N;++i)
		{
			while(!q[i].empty())
				q[i].pop();
		}
		while(!glob.empty())
			glob.pop();
	}
	return 0;
}