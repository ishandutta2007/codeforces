#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1000005,M=1000005,INF=0X3F3F3F3F;
int n,m,mf,mc,S,T;
int pp=1,d[N],lnk[N],dis[N],pre[N],nxt[M],to[M],w[M],c[M];
void jb(int k1,int k2,int k3,int k4){
//	D("jb:%d %d %d %d\n",k1,k2,k3,k4);
	to[++pp]=k2,w[pp]=k3,c[pp]=k4,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,w[pp]=0,c[pp]=-k4,nxt[pp]=lnk[k2],lnk[k2]=pp;
}
void ae(int k1,int k2,int k3,int k4,int k5){
	if(k3<=k4){
		jb(k1,k2,k4-k3,k5);
		d[k1]-=k3,d[k2]+=k3;
		mc+=k3*k5;
	}
}
bool spfa(){
	static bool inq[N];
	rep(i,1,T)dis[i]=INF;dis[S]=0;queue<int>q;q.push(S),inq[S]=1;
	while(q.size()){
		int k1=q.front();q.pop();inq[k1]=0;
		for(int i=lnk[k1];i;i=nxt[i])if(w[i]>0&&dis[k1]+c[i]<dis[to[i]]){
			pre[to[i]]=i;
			dis[to[i]]=dis[k1]+c[i];
			if(!inq[to[i]]){
				inq[to[i]]=1;
				q.push(to[i]);
			}
		}
	}
	if(dis[T]!=INF)return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2,k3,k4;scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
		if(k4<=k3){
			mc-=k4;
			ae(k1,k2,k4,k3,1);
			jb(k1,k2,INF,2);
			jb(k2,k1,k4,1);
		}else{
			mc+=k4-k3;
			ae(k1,k2,k3,k4,0);
			jb(k1,k2,INF,2);
			jb(k2,k1,k3,1);
		}
	}
	S=n+1,T=n+2;
	rep(i,1,n){
		if(d[i]>0)jb(S,i,d[i],0);
		if(d[i]<0)jb(i,T,-d[i],0);
	}
	jb(n,1,INF,0);
	while(spfa()){
		int mn=INF;
		for(int i=pre[T];i;i=pre[to[i^1]])mn=min(mn,w[i]);
		for(int i=pre[T];i;i=pre[to[i^1]])w[i]-=mn,w[i^1]+=mn;
		mf+=mn;
		mc+=dis[T]*mn;
	}
	printf("%d\n",mc);
	return 0;
}