#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int max_m=1e5+5;
vector<P> edge[max_m];
const int max_n=1e5+5;
int col[max_n],vis[max_n],fa[max_n],cnt_col;
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
		fa[x]=y;
}
vector<int> c[max_n];
const int B=200;
bitset<B> now;
vector<bitset<B> > b(1);
const int max_B=500+5;
int id[max_n][max_B];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[c].push_back(P(a,b));
	}
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		for(vector<P>::iterator it=edge[i].begin();it!=edge[i].end();++it)
			merge(it->first,it->second);
		for(vector<P>::iterator it=edge[i].begin();it!=edge[i].end();++it)
		{
			int u=it->first;
			if(vis[u]!=i)
			{
				if(!col[get_fa(u)])
					col[fa[u]]=++cnt_col;
				c[u].push_back(col[fa[u]]);
				vis[u]=i;
			}
			u=it->second;
			if(vis[u]!=i)
			{
				if(!col[get_fa(u)])
					col[fa[u]]=++cnt_col;
				c[u].push_back(col[fa[u]]);
				vis[u]=i;
			}
		}
		for(vector<P>::iterator it=edge[i].begin();it!=edge[i].end();++it)
		{
			int u=it->first;
			fa[u]=u,col[u]=0;
			u=it->second;
			fa[u]=u,col[u]=0;
		}
	}
	assert(cnt_col<=m);
	for(int i=1;i<=n;++i)
		for(int j=0;j<int(c[i].size());++j)
		{
			int k=(c[i][j]-1)/B;
			int L=k*B+1,R=(k+1)*B;
			now.reset();
			while(j<(int)c[i].size()&&c[i][j]>=L&&c[i][j]<=R)
				now[c[i][j++]-L]=true;
			b.push_back(now);
			id[i][k]=(int)b.size()-1;
			--j;
		}
	int q;
	scanf("%d",&q);
	int cnt_blocks=(n+B-1)/B;
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int ans=0;
		for(int i=0;i<=cnt_blocks-1;++i)
		{
			if(id[u][i]&&id[v][i])
				ans+=(b[id[u][i]]&b[id[v][i]]).count();
		}
		printf("%d\n",ans);
	}
	return 0;
}