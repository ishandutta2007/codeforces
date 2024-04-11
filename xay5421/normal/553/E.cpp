#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=105;
const double PI=acos(-1);
int n,m,t,x;
int pp,lnk[N],nxt[N],to[N],we[N];
void ae(int k1,	int k2,int k3){
	to[++pp]=k2,nxt[pp]=lnk[k1],we[pp]=k3,lnk[k1]=pp;
}
priority_queue<pair<int,int> >q;
int dis[N];
bool vis[N];
void dij(){
	memset(dis,63,sizeof(dis));
	dis[n]=0;
	auto push=[&](int k1){
		q.emplace(-dis[k1],k1);
	};
	push(n);
	while(SZ(q)){
		int k1=q.top().Y;
		q.pop();
		if(vis[k1])continue;
		vis[k1]=1;
		for(int i=lnk[k1];i;i=nxt[i])if(dis[k1]+we[i]<dis[to[i]]){
			dis[to[i]]=dis[k1]+we[i];
			push(to[i]);
		}
	}
}
struct cp{
	double x,y;
	cp operator+(const cp&k)const{return(cp){x+k.x,y+k.y};}
	cp operator-(const cp&k)const{return(cp){x-k.x,y-k.y};}
	cp operator*(const cp&k)const{return(cp){x*k.x-y*k.y,x*k.y+y*k.x};}
}A[200005],B[200005];
queue<int>Q;
int lim;
double p[N][200005],tmp[200005],f[N][200005];
void fft(cp*a,int o){
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=(lim>>1);(j^=k)<k;k>>=1);
	}
	for(int i=1;i<lim;i<<=1){
		cp wn=(cp){double(cos(PI/i)),double(o*sin(PI/i))};
		for(int j=0;j<lim;j+=i<<1){
			cp w=(cp){1,0};
			for(int k=0;k<i;++k,w=w*wn){
				cp x=a[j+k],y=a[i+j+k]*w;
				a[j+k]=x+y,a[i+j+k]=x-y;
			}
		}
	}
	if(o==-1){
		rep(i,0,lim-1)a[i].x/=lim;
	}
}
void pmul(double*a,double*b,double*c){
	rep(i,0,lim/2)A[i]=(cp){a[i],0},B[i]=(cp){b[i],0};
	rep(i,lim/2+1,lim-1)A[i]=(cp){0,0},B[i]=(cp){0,0};
	fft(A,1),fft(B,1);
	rep(i,0,lim-1)A[i]=A[i]*B[i];
	fft(A,-1);
	rep(i,0,lim-1)c[i]=A[i].x;
}
void spfa(){
	rep(i,1,n){
		rep(j,0,t)f[i][j]=1e100;
		rep(j,t+1,t*2)f[i][j]=dis[i]+x;
	}
	rep(j,0,t)f[n][j]=0;
	memset(vis,0,sizeof(vis));
	Q.push(n);
	auto fun=[&](int u,int v,int eid,int w)->bool{
		pmul(f[u],p[eid],tmp);
		bool flg=0;
		rep(i,0,t)if(f[v][i]>tmp[t+1+i]+w){
			flg=1;
			f[v][i]=tmp[t+1+i]+w;
		}
		return flg;
	};
	while(SZ(Q)){
		int k1=Q.front();
		Q.pop();
		for(int i=lnk[k1];i;i=nxt[i]){
			if(fun(k1,to[i],i,we[i])){
				if(!vis[to[i]]){
					vis[to[i]]=1;
					Q.push(to[i]);
				}
			}
		}
		vis[k1]=0;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&x);
	lim=1;
	while(lim<=t*4)lim<<=1;
	rep(i,1,m){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		ae(k2,k1,k3);
		rep(j,1,t)scanf("%lf",&p[i][t+1-j]),p[i][t+1-j]/=1e5;
	}
	dij();
	spfa();
	printf("%.20f\n",f[1][0]);
	return 0;
}