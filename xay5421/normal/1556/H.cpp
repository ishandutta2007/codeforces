// author: xay5421
// created: Mon Aug 30 14:03:29 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=55,INF=0X3F3F3F3F;
int n,K,d[N],d_[N],dd[N],cost[N][N];
struct ufs{
	int fa[N];
	void init(){rep(i,1,n)fa[i]=i;}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	bool mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
	bool can(int k1,int k2){
		return fd(k1)!=fd(k2);
	}
}o,o_;
int m,u[N*N],v[N*N],w[N*N],in[N*N];
int S,T;
int pp,lnk[N*N],to[N*N*N],nxt[N*N*N];
void ae(int k1,int k2){
	/*D("ae ");
	if(k1==S)D("S ");else D("%d ",k1);
	if(k2==T)D("T\n");else D("%d\n",k2);*/
	to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
int V(int k1){
	return k1>m?0:in[k1]?-w[k1]:w[k1];
}
bool can_(int k1,int k2){
	return dd[k1]+1<=d[k1]&&dd[k2]+1<=d[k2];
}
const int TT=(1<<20)-1;
int dis[N*N*N],cnt[N*N*N],pre[N*N*N],vis[N*N*N],q[TT+5];
bool spfa(){
	fill(dis+1,dis+1+T,INF);
	fill(pre+1,pre+1+T,0);
	int he=0,ta=0;
	dis[S]=0,cnt[S]=0,vis[S]=1;
	q[++ta]=S;
	while(he!=ta){
		int k1=q[++he&=TT]; vis[k1]=0;
		for(int i=lnk[k1];i;i=nxt[i]){
			int now=dis[k1]+V(to[i]);
			if(now<dis[to[i]]||(now==dis[to[i]]&&cnt[k1]+1<cnt[to[i]])){
				dis[to[i]]=now,cnt[to[i]]=cnt[k1]+1,pre[to[i]]=k1;
				if(!vis[to[i]]){
					vis[to[i]]=1;
					q[++ta&=TT]=to[i];
				}
			}
		}
	}
	return pre[T]>0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	rep(i,1,K)scanf("%d",&d[i]);
	rep(i,K+1,n)d[i]=INF;
	rep(i,1,n)rep(j,i+1,n)scanf("%d",&cost[i][j]);
	rep(i,1,n)rep(j,max(K+1,i+1),n)u[++m]=i,v[m]=j,w[m]=cost[i][j];
	int ans=INF;
	rep(s,0,(1<<(K*(K-1)/2))-1){
		rep(i,1,m)in[i]=0;
		o.init();
		rep(i,1,n)d_[i]=0;
		int bit=0,flg=1,ss=0;
		rep(i,1,K)rep(j,i+1,K)if(s>>(bit++)&1)flg&=o.mer(i,j),++d_[i],++d_[j],ss+=cost[i][j];
		rep(i,1,K)flg&=(d_[i]<=d[i]);
		if(!flg)continue;
		o_=o;
		while(1){
			o=o_;
			rep(i,1,n)dd[i]=d_[i];
			S=m+1,T=m+2;
			fill(lnk+1,lnk+1+T,0);
			pp=0;
			rep(i,1,m)if(in[i]){
				++dd[u[i]],++dd[v[i]];
				o.mer(u[i],v[i]);
			}
			rep(i,1,m)if(!in[i]){
				if(can_(u[i],v[i])){
					ae(i,T);
				}
				if(o.can(u[i],v[i])){
					ae(S,i);
				}
			}
			rep(i,1,m)if(in[i]){
				o=o_;
				rep(j,1,n)dd[j]=d_[j];
				rep(j,1,m)if(j!=i&&in[j]){
					++dd[u[j]],++dd[v[j]];
					o.mer(u[j],v[j]);
				}
				rep(j,1,m)if(!in[j]){
					if(can_(u[j],v[j])){
						ae(j,i);
					}
					if(o.can(u[j],v[j])){
						ae(i,j);
					}
				}
			}
			if(!spfa())break;
			for(int i=pre[T];i!=S;i=pre[i]){
				in[i]^=1;
			}
		}
		int cur=0;
		rep(i,1,m)cur+=in[i]*w[i];
		if(count(in+1,in+1+m,1)+__builtin_popcount(s)==n-1)ans=min(ans,cur+ss);
	}
	printf("%d\n",ans);
	return 0;
}