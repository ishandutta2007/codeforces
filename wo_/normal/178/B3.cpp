#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> G[100100];

//double edge
vector<int> dG[100100];
bool used[100100];
int rpre[100100];

int r=0;
void dfs(int v,int p)
{
	used[v]=true;
	rpre[r]=v;
	r++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dG[G[v][i]].push_back(v);
		if(used[G[v][i]]==true) continue;
		dfs(G[v][i],v);
	}
}

int num[100100];
int c=0;
void rdfs(int v)
{
	num[v]=c;
	for(int i=0;i<dG[v].size();i++)
	{
		if(num[dG[v][i]]!=-1) continue;
		rdfs(dG[v][i]);
	}
}

//LCA
vector<int> tG[100100];
struct RmQ{
	int N;
	int dat[524288];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=N*2-1;i++) dat[i]=1<<29;
	}
	void update(int id,int x)
	{
		id+=N;
		while(id>0)
		{
			dat[id]=min(dat[id],x);
			id/=2;
		}
	}
	int query(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return 1<<29;
		if(l<=a&&b<=r) return dat[k];
		return min(query(l,r,k*2,a,(a+b)/2),query(l,r,k*2+1,(a+b)/2,b));
	}
	int query(int l,int r)
	{
		return query(l,r,1,0,N);
	}
};

RmQ rmq;

int dep[100100];
vector<int> vs;
int pre[100100];

void tdfs(int v,int p,int d)
{
	if(pre[v]==-1) pre[v]=vs.size();
	dep[v]=d;
	for(int i=0;i<tG[v].size();i++)
	{
		if(tG[v][i]==p) continue;
		vs.push_back(v);
		tdfs(tG[v][i],v,d+1);
	}
	vs.push_back(v);
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(used,false,sizeof(used));
	dfs(0,-1);
	memset(num,-1,sizeof(num));
	for(int i=0;i<N;i++)
	{
		if(num[rpre[i]]==-1)
		{
			rdfs(rpre[i]);
			c++;
		}
	}
	if(c==1)
	{
		int K;
		scanf("%d",&K);
		for(int i=0;i<K;i++) printf("%d\n",0);
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(num[i]!=num[G[i][j]])
			{
				tG[num[i]].push_back(num[G[i][j]]);
			}
		}
	}
	for(int i=0;i<c;i++)
	{
		sort(tG[i].begin(),tG[i].end());
		tG[i].erase(unique(tG[i].begin(),tG[i].end()),tG[i].end());
	}
	memset(pre,-1,sizeof(pre));
	tdfs(0,-1,0);
	rmq.init(vs.size());
	for(int i=0;i<vs.size();i++)
	{
		rmq.update(i,dep[vs[i]]);
	}
	int K;
	//for(int i=0;i<vs.size();i++) printf("%d ",vs[i]);
	//puts("");
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		if(num[a]==num[b])
		{
			printf("0\n");
			continue;
		}
		int aid=pre[num[a]],bid=pre[num[b]];
		int d=rmq.query(min(aid,bid),max(aid,bid)+1);
	//	printf("%d %d\n",aid,bid);
		printf("%d\n",dep[num[a]]+dep[num[b]]-2*d);
	}
	return 0;
}