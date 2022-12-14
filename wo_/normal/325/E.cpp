#include<cstdio>
#include<vector>

using namespace std;

struct UnionFind{
	int par[100100];
	int rank[100100];
	void init(int N)
	{
		for(int i=0;i<N;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int i)
	{
		if(i==par[i]) return i;
		return par[i]=find(par[i]);
	}
	void unite(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

UnionFind uf;

int nxt[100100];
int N;

int get(int x,int i)
{
	int res=x*2+i;
	return res%N;
}

int main()
{
	scanf("%d",&N);
	if(N%2==1)
	{
		printf("-1\n");
		return 0;
	}
	int n=N/2;
	uf.init(N);
	for(int i=0;i<n;i++)
	{
		nxt[i]=get(i,1);
		nxt[i+n]=get(i+n,0);
		uf.unite(i,nxt[i]);
		uf.unite(i+n,nxt[i+n]);
	}
	for(int i=0;i<n;i++)
	{
		if(uf.same(i,i+n)==true) continue;
		swap(nxt[i],nxt[i+n]);
		uf.unite(i,i+n);
	}
	int id=0;
	do{
		printf("%d ",id);
		id=nxt[id];
	}while(id!=0);
	printf("0\n");
	return 0;
}