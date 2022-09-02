#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=1005;
int n,fv,d[N],q[N],len,ans[100005][3];
struct ed{ed*nxt;int to,w;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v,int w){*++p=(ed){lnk[u],v,w},lnk[u]=p;}
int get(int u,int fa){
	if(d[u]==2){
		for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa)return get(i->to,u); 
	}return fv=fa,u; 
}
void dfs(int u,int fa,int lim){
	if(d[u]==1){
		q[lim]=u;
		return;
	}
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa){
		dfs(i->to,u,lim);
		if(*q==lim)return; 
	}
}
void push(int a,int b,int c){
	if(a==b)return;
	ans[++len][0]=a,ans[len][1]=b,ans[len][2]=c;
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		ae(u,v,w),ae(v,u,w),++d[u],++d[v];
	}
	rep(i,1,n)if(d[i]==2){
		int w=0;
		for(ed*j=lnk[i];j;j=j->nxt){
			if(w!=0&&j->w!=w)return puts("NO"),0;
			w=j->w;
		}
	}
	rep(i,1,n)if(d[i]!=2){
		int u=i;
		for(ed*j=lnk[i];j;j=j->nxt){
			int fu=j->to,v=get(j->to,u),w=j->w>>1;
			if(u>v)continue;
			*q=0;int now=0;
			if(d[u]==1)q[0]=q[1]=u,now=2;else
				for(ed*k=lnk[u];k;k=k->nxt)if(k->to!=fu){
					dfs(k->to,u,now++);if(now==2)break;
				}
			if(d[v]==1)q[2]=q[3]=v;else
				for(ed*k=lnk[v];k;k=k->nxt)if(k->to!=fv){
					dfs(k->to,v,now++);if(now==4)break;
				}
			push(q[0],q[2],w);
			push(q[1],q[3],w);
			push(q[0],q[1],-w);
			push(q[2],q[3],-w);
		}
	}
	puts("YES");
	printf("%d\n",len);
	for(int i=1;i<=len;++i)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}