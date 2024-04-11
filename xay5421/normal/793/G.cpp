#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=10005,M=2000005,INF=0X3F3F3F3F;
int n,p0,Q,S,T;
int ind;
int pp=1,lnk[M],nxt[M],to[M],we[M];
void ae(int k1,int k2,int k3){
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,we[pp]= 0,nxt[pp]=lnk[k2],lnk[k2]=pp;
}
struct sgt{
	int cov[N*4],id[N*4];
	void upd(int k1){
		id[k1]=++ind;
		if(!cov[k1*2]){
			ae(id[k1],id[k1*2],INF);
		}
		if(!cov[k1*2+1]){
			ae(id[k1],id[k1*2+1],INF);
		}
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			cov[k1]+=k6;
			return;
		}
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			id[k1]=k2+n;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
}A;
struct ff{
	int x,l,r,w;
	bool operator<(const ff&k)const{
		return x<k.x;
	}
}p[N*2];
int dep[M],cur[M];
bool bfs(){
	queue<int>q;
	q.push(S);
	memset(dep,63,(T+1)*4);
	dep[S]=0;
	while(SZ(q)){
		int k1=q.front();
		q.pop();
		for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1<dep[to[i]]){
			dep[to[i]]=dep[k1]+1;
			q.push(to[i]);
		}
	}
	return dep[T]<INF;
}
int dfs(int k1,int val){
	if(k1==T)return val;
	int v=val;
	for(int&i=cur[k1];i;i=nxt[i])if(dep[to[i]]==dep[k1]+1&&we[i]){
		int f=dfs(to[i],min(v,we[i]));
		v-=f,we[i]-=f,we[i^1]+=f;
		if(!v)return val;
	}
	return val-v;
}
int dinic(){
	int res=0;
	while(bfs()){
		memcpy(cur,lnk,(T+1)*4);
		res+=dfs(S,INF);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q),ind=n*2;
	rep(i,1,Q){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		p[++p0]=(ff){a,b,d,1};
		p[++p0]=(ff){c+1,b,d,-1};
	}
	sort(p+1,p+1+p0);
	A.bud(1,1,n);
	int j=1;
	for(int i=1;i<=n;++i){
		while(j<=p0&&p[j].x==i)A.mdf(1,1,n,p[j].l,p[j].r,p[j].w),++j;
		if(!A.cov[1]){
			ae(i,A.id[1],INF);
		}
	}
	S=++ind,T=++ind;
	rep(i,1,n)ae(S,i,1);
	rep(i,1,n)ae(i+n,T,1);
	printf("%d\n",dinic());
	return 0;
}