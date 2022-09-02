// author: xay5421
// created: Mon Jun 28 08:36:50 2021
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
typedef long long LL;
const int N=4405,INF=0X3F3F3F3F;
int n,a[N],b[N],id[N],id_[N],bin[N],tmp[N];
void chk0(){
	int p1=1,p2=1;
	rep(i,1,n){
		while(id[p1]>n)++p1;
		while(id[p2]<=n)++p2;
		if(b[id[p1]]<b[id[p2]])return;
		++p1,++p2;
	}
	printf("%d %d\n",0,n);
	exit(0);
}
bool chk(LL mid){
	fill(bin+1,bin+1+n*2,0);
	sort(id_+1,id_+1+n*2,[&](int x,int y){
		LL k1=a[x]*mid+b[x],k2=a[y]*mid+b[y];
		return k1^k2?k1<k2:b[x]^b[y]?b[x]>b[y]:x>y;
	});
	rep(i,1,n*2)tmp[id_[i]]=i;
	rep(i,2,n*2)tmp[id[i]]=max(tmp[id[i]],tmp[id[i-1]]);
	rep(i,1,n)++bin[tmp[i]];
	int t=0;
	per(i,n*2,1){
		t+=bin[i];
		if(id_[i]>n)--t;
		if(t<0)return 0;
	}
	return 1;
}
const int N_=N*2,M=250005,TT=(1<<19)-1;
int S,T,ind,q[TT+10],vis[N_],pre[N_],dis[N_];
vector<int>vec[N];
int pp=1,lnk[N_],nxt[M],to[M],we[M],co[M];
void ae(int k1,int k2,int k3,int k4){
	D("ae %d %d %d %d\n",k1,k2,k3,k4);
	to[++pp]=k2,we[pp]=k3,co[pp]=k4,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,we[pp]=0,co[pp]=-k4,nxt[pp]=lnk[k2],lnk[k2]=pp;
}
bool spfa(){
	fill(dis+1,dis+1+ind,INF);
	fill(pre+1,pre+1+ind,0);
	int he=0,ta=0;
	q[++ta]=S,vis[S]=1,dis[S]=0;
	while(he!=ta){
		int k1=q[++he&=TT];
		D("k1=%d dis=%d\n",k1,dis[k1]);
		vis[k1]=0;
		for(int i=lnk[k1];i;i=nxt[i])if(we[i]>0&&dis[k1]+co[i]<dis[to[i]]){
			dis[to[i]]=dis[k1]+co[i];
			pre[to[i]]=i;
			if(!vis[to[i]]){
				vis[to[i]]=1;
				q[++ta&=TT]=to[i];
			}
		}
	}
	return dis[T]!=INF;
}
void sol(){
	ind=n*2;
	S=++ind,T=++ind;
	rep(i,1,n*2){
		if(i<=n)ae(S,i,1,0);else ae(i,T,1,0);
	}
	int cur=0;
	rep(_,1,n*2){
		int i=id[_];
		if(i<=n){
			if(cur)ae(i,cur,1,1);
		}else{
			++ind;
			if(cur)ae(ind,cur,INF,0);
			cur=ind;
			ae(cur,i,1,0);
		}
	}
	cur=0;
	rep(i,1,n)vec[tmp[i]].push_back(i);
	rep(_,1,n*2){
		int i=id_[_];
		if(cur){
			for(auto x:vec[_]){
				ae(x,cur,1,2);
			}
		}
		if(i<=n){
			if(cur)ae(i,cur,1,1);
		}else{
			++ind;
			if(cur)ae(ind,cur,INF,0);
			cur=ind;
			ae(cur,i,1,0);
		}
	}
	assert(ind<N_);
	int ans=0;
	while(spfa()){
		int f=INF;
		for(int i=pre[T];i;i=pre[to[i^1]])f=min(f,we[i]);
		for(int i=pre[T];i;i=pre[to[i^1]])we[i]-=f,we[i^1]+=f;
		ans+=dis[T]*f;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%d%d",&a[i],&b[i]),id[i]=id_[i]=i;
	sort(id+1,id+1+n*2,[&](int x,int y){return b[x]^b[y]?b[x]<b[y]:a[x]^a[y]?a[x]>a[y]:x>y;});
	chk0();
	LL l=1,r=2e9,ans1=1e18;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(chk(mid))ans1=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans1==1e18)puts("-1"),exit(0);
	printf("%lld ",ans1);
	chk(ans1);
	sol();
	return 0;
}