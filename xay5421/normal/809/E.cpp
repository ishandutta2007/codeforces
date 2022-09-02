#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
const int N=200005,K=20,P=1000000007;
int n,ans,ind,cnt,top,a[N],ia[N],st[N],F[N],q[N],p[N],phi[N]={0,1},dep[N],fa[N][K],tin[N],tou[N],s1[N],s2[N];bool vis[N]={1,1};
int fpow(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;return res;}
struct ed{ed*nxt;int to;}pool[N<<1],*pp=pool,*lnk[N];
void ae(int u,int v){*++pp=(ed){lnk[u],v},lnk[u]=pp;}
bool cmp(int x,int y){return tin[x]<tin[y];}
void sieve(){
	for(int i=2;i<N;++i){
		if(!vis[i])p[++*p]=i,phi[i]=i-1;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			vis[i*p[j]]=1;
			if(i%p[j])phi[i*p[j]]=phi[i]*(p[j]-1);
			else{phi[i*p[j]]=phi[i]*p[j];break;}
		}
	}
}
void dfs(int u){
	tin[u]=++ind;
	for(int i=1;i<K;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa[u][0])fa[i->to][0]=u,dep[i->to]=dep[u]+1,dfs(i->to);
	tou[u]=ind;
}
int lca(int u,int v){
	if(dep[u]<dep[v])u^=v^=u^=v;int ret=dep[u]-dep[v];
	per(i,K-1,0)if(ret>>i&1)u=fa[u][i];if(u==v)return u;
	per(i,K-1,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];return fa[u][0];
}
void add(int u,int v){
	int s3=(s1[u]+1ll*(dep[u]-dep[v])*s2[u]%P)%P;
	ans=(ans+1ll*s3*s2[v]%P+1ll*s2[u]*s1[v]%P)%P;
	(s1[v]+=s3)%=P;
	(s2[v]+=s2[u])%=P;
}
int solve(int d){
	cnt=top=ans=0;for(int j=d;j<=n;j+=d)q[++cnt]=ia[j];
	std::sort(q+1,q+1+cnt,cmp);int rt=lca(q[1],q[cnt]);
	if(rt!=q[1]){
		st[++top]=rt;
		s1[rt]=s2[rt]=0;
	}
	for(int i=1;i<=cnt;++i){
		if(i>=2){
			int lca=::lca(q[i],q[i-1]);
			while(dep[st[top]]>dep[lca])
				if(dep[st[top-1]]<dep[lca]){
					s1[lca]=s2[lca]=0;
					add(st[top],lca);
					st[top]=lca;
				}else{
					add(st[top],st[top-1]);
					--top;
				}
		}
		st[++top]=q[i],s1[q[i]]=0,s2[q[i]]=phi[a[q[i]]];
	}
	while(top>1){
		add(st[top],st[top-1]);
		--top;
	}
	return ans*2%P;
}
int main(){
	sieve();
	scanf("%d",&n);rep(i,1,n)scanf("%d",a+i),ia[a[i]]=i;rep(i,2,n){int u,v;scanf("%d%d",&u,&v);ae(u,v),ae(v,u);}dfs(dep[1]=1);
	for(int i=1;i<=n;++i)F[i]=solve(i);
	int res=0;
	for(int i=n;i>=1;--i){
		for(int j=i+i;j<=n;j+=i)F[i]=(F[i]-F[j]+P)%P;
		res=(res+1ll*F[i]*i%P*fpow(phi[i],P-2)%P)%P;
	}
	res=1ll*res*fpow(n,P-2)%P*fpow(n-1,P-2)%P;
	printf("%d\n",res);
	return 0;
}