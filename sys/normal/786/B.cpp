#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,s,q,cnt,ct,head[10*Maxn];
long long dis[10*Maxn];
bool vis[10*Maxn];
struct edg
{
	int nxt,to,w;
}edge[40*Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(edg){head[x],y,w};
	head[x]=cnt;
}
struct Tree
{
	int lt,rt,id;
}in[4*Maxn],out[4*Maxn];
void build(int root,int lt,int rt)
{
	in[root]=out[root]=(Tree){lt,rt,0};
	in[root].id=++ct,out[root].id=++ct;
	add(in[root].id,out[root].id,0);
	if(lt+1!=rt)
	{
		int mid=(lt+rt)/2;
		build(root<<1,lt,mid);
		build(root<<1|1,mid,rt);
		add(in[root].id,in[root<<1].id,0);
		add(in[root].id,in[root<<1|1].id,0);
		add(out[root<<1].id,out[root].id,0);
		add(out[root<<1|1].id,out[root].id,0);
	}
}
struct sta
{
	int id;
	long long w;
	bool operator < (const sta &tmp) const
	{
		return w>tmp.w;
	}
};
int get_id(int x,bool is_out=0)
{
	int root=1;
	while(in[root].lt+1!=in[root].rt)
	{
//		lt=in[root].lt,rt=in[root].rt;
		int mid=(in[root].lt+in[root].rt)/2;
		if(x>=mid) root=root<<1|1;
		else root=root<<1;
	}
	if(is_out) return out[root].id;
	return in[root].id;
}

void dijkstra(void)
{
	s=get_id(s);
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue <sta> Pr;
	while(!Pr.empty()) Pr.pop();
	Pr.push((sta){s,0});
	while(!Pr.empty())
	{
		int u=Pr.top().id;
		Pr.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to,w=edge[i].w;
			if(dis[to]>dis[u]+w)
			{
				dis[to]=dis[u]+w;
				Pr.push((sta){to,dis[to]});
			}
		}
	}
}
void work1(int root,int lt,int rt,int v,int w,int tmp)
{
	if(lt==in[root].lt&&rt==in[root].rt) add(tmp,in[root].id,0);
	else
	{
		int mid=(in[root].lt+in[root].rt)/2;
		if(mid<=lt) work1(root<<1|1,lt,rt,v,w,tmp);
		else if(mid>=rt) work1(root<<1,lt,rt,v,w,tmp);
		else
		{
			work1(root<<1,lt,mid,v,w,tmp);
			work1(root<<1|1,mid,rt,v,w,tmp);
		}
	}
}
void work2(int root,int lt,int rt,int v,int w,int tmp)
{
	if(lt==in[root].lt&&rt==in[root].rt) add(out[root].id,tmp,0);
	else
	{
		int mid=(in[root].lt+in[root].rt)/2;
		if(mid<=lt) work2(root<<1|1,lt,rt,v,w,tmp);
		else if(mid>=rt) work2(root<<1,lt,rt,v,w,tmp);
		else
		{
			work2(root<<1,lt,mid,v,w,tmp);
			work2(root<<1|1,mid,rt,v,w,tmp);
		}
	}
}
void print(int root,int lt,int rt)
{
	if(lt+1==rt) printf("%lld ",dis[in[root].id]==0x3f3f3f3f3f3f3f3f?-1:dis[in[root].id]);
	else
	{
		int mid=(lt+rt)/2;
		print(root<<1,lt,mid);
		print(root<<1|1,mid,rt);
	}
}
int main()
{
	scanf("%d%d%d",&n,&q,&s);
	build(1,1,n+1);
	for(int i=1;i<=q;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(get_id(u,1),get_id(v),w);
		}
		if(opt==2)
		{
			int l,r,v,w;
			scanf("%d%d%d%d",&v,&l,&r,&w);
			int tmp=++ct;
			add(get_id(v,1),tmp,w);
			work1(1,l,r+1,v,w,tmp);
		}
		if(opt==3)
		{
			int l,r,v,w;
			scanf("%d%d%d%d",&v,&l,&r,&w);
			int tmp=++ct;
			add(tmp,get_id(v),w);
			work2(1,l,r+1,v,w,tmp);
		}
	}
	dijkstra();
	print(1,1,n+1);
	return 0;
}