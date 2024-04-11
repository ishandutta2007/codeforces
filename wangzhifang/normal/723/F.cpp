#include <cstdio>
#include <cstring>
#define max_n 200000
#define max_m 400000
using namespace std;
int ans[max_n][2],f[max_n+1],ls[max_n+1],lt[max_n+1],anscnt;
struct node{
	int v,nxt;
	node(){}
	node(int _v,int _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int head[max_n+1];
	int cnt;
	node edge[max_m<<1];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void insert(int u,int v){
		push(u,v);
		push(v,u);
	}
	void push(int u,int v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
graph g;
int findrt(int x){
	return f[x]==x?x:(f[x]=findrt(f[x]));
}
bool merge(int u,int v){
	int x=findrt(u),y=findrt(v);
	if(x==y)
		return 0;
	x<y?(f[y]=x):(f[x]=y);
	return 1;
}
void pushans(int u,int v){
	++anscnt;
	ans[anscnt][0]=u,ans[anscnt][1]=v;
}
int main(){
	int n,m,s,t,ds,dt;
	scanf("%d%d",&n,&m),g.build(),anscnt=0;
	for(int i=0,u,v; ++i<=m; g.insert(u,v))
		scanf("%d%d",&u,&v);
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	for(int i=0; ++i<=n; f[i]=i);
	for(int u=0; ++u<=n; ){
		if(u==s||u==t)
			continue;
		for(int i=g.head[u],v; ~i; i=g.edge[i].nxt)
			(v=g.edge[i].v)!=s&&v!=t&&merge(u,v)&&(pushans(u,v),1);
	}
	for(int i=g.head[s],v; ~i; i=g.edge[i].nxt)
		(v=g.edge[i].v)!=t&&(ls[findrt(v)]=v);
	for(int i=g.head[t],v; ~i; i=g.edge[i].nxt)
		(v=g.edge[i].v)!=s&&(lt[findrt(v)]=v);
	for(int i=0; ++i<=n; ){
		if(ls[i]&&!lt[i])
			--ds,merge(s,i),pushans(s,ls[i]);
		else
			if(!ls[i]&&lt[i])
				--dt,merge(t,i),pushans(t,lt[i]);
		if(ds<0||dt<0){
			puts("No");
			return 0;
		}
	}
	for(int i=0; ++i<=n; )
		if(ls[i]&&lt[i]){
			ds&&merge(s,i)&&(pushans(s,ls[i]),--ds);
			dt&&merge(t,i)&&(pushans(t,lt[i]),--dt);
			if(findrt(s)!=findrt(i)||findrt(t)!=findrt(i)){
				puts("No");
				return 0;
			}
		}
	if(findrt(s)!=findrt(t)){
		bool flag=0;
		for(int i=g.head[s]; ~i; i=g.edge[i].nxt)
			if(g.edge[i].v==t){
				flag=1;
				break;
			}
		if(!flag){
			puts("No");
			return 0;
		}
		ds&&dt&&(pushans(s,t),1);
	}
	if(anscnt!=n-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0; ++i<n; printf("%d %d\n",ans[i][0],ans[i][1]));
	return 0;
}