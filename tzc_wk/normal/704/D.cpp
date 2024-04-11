#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MAXV=4e5+4;
const int MAXE=3e6;
const int INF=0x3f3f3f3f;
int n,m,r,b,rv=0,S1,T1,S2,T2,x[MAXN+5],y[MAXN+5],eid[MAXN+5];
int kx[MAXN*2+5],cx=0,ux[MAXN*2+5],nx=0;
int ky[MAXN*2+5],cy=0,uy[MAXN*2+5],ny=0;
struct restri{int t,x,d;} a[MAXN+5];
int mnx[MAXN*2+5],mny[MAXN*2+5],cntx[MAXN*2+5],cnty[MAXN*2+5];
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
}
void deledge(int x){hd[x]=nxt[hd[x]];ec--;}
int sum=0;
void adde(int u,int v,int l,int r){
//	printf("%d %d %d %d\n",u,v,l,r);
	if(l>r) puts("-1"),exit(0);sum+=l;
	adde(u,T2,l);adde(S2,v,l);adde(u,v,r-l);
}
int dep[MAXV+5],now[MAXV+5];
bool getdep(int S,int T){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;now[y]=hd[y];
				q.push(y);
			}
		}
	} return ~dep[T];
}
int getflow(int x,int T,int f){
	if(x==T) return f;int res=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(dep[y]==dep[x]+1&&z){
			int w=getflow(y,T,min(f-res,z));
			cap[e]-=w;cap[e^1]+=w;res+=w;
			if(res==f) return res;
		}
	} return res;
}
int dinic(int S,int T){
	int ret=0;
	while(getdep(S,T)) ret+=getflow(S,T,INF);
	return ret;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&b);if(r>b) r^=b^=r^=b,rv=1;
	for(int i=1;i<=n;i++){scanf("%d%d",&x[i],&y[i]);kx[++cx]=x[i];ky[++cy]=y[i];}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].d);
		if(a[i].t==1) kx[++cx]=a[i].x;
		else ky[++cy]=a[i].x;
	} sort(kx+1,kx+cx+1);sort(ky+1,ky+cy+1);
	for(int i=1;i<=cx;i++) if(kx[i]^kx[i-1]) ux[++nx]=kx[i];
	for(int i=1;i<=cy;i++) if(ky[i]^ky[i-1]) uy[++ny]=ky[i];
	for(int i=1;i<=n;i++){
		x[i]=lower_bound(ux+1,ux+nx+1,x[i])-ux;
		y[i]=lower_bound(uy+1,uy+ny+1,y[i])-uy;
		cntx[x[i]]++;cnty[y[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(a[i].t==1) a[i].x=lower_bound(ux+1,ux+nx+1,a[i].x)-ux;
		else a[i].x=lower_bound(uy+1,uy+ny+1,a[i].x)-uy;
	}
	memset(mnx,63,sizeof(mnx));memset(mny,63,sizeof(mny));
	T2=(S2=(T1=(S1=nx+ny+1)+1)+1)+1;
	for(int i=1;i<=m;i++){
		if(a[i].t==1) chkmin(mnx[a[i].x],a[i].d);
		else chkmin(mny[a[i].x],a[i].d);
	}
	for(int i=1;i<=nx;i++){
		int lwb=max((cntx[i]-mnx[i]+1)/2,0);
		int upb=min((cntx[i]+mnx[i])/2,cntx[i]);
		adde(S1,i,lwb,upb);
	}
	for(int i=1;i<=ny;i++){
//		printf("%d %d\n",i,mny[i]);
		int lwb=max((cnty[i]-mny[i]+1)/2,0);
		int upb=min((cnty[i]+mny[i])/2,cnty[i]);
		adde(i+nx,T1,lwb,upb);
	}
	for(int i=1;i<=n;i++) adde(x[i],y[i]+nx,1),eid[i]=ec;
	adde(T1,S1,INF);if(dinic(S2,T2)!=sum) return puts("-1"),0;
	int res=cap[ec];deledge(S1);deledge(T1);
	res+=dinic(S1,T1);//printf("%d\n",res);
	printf("%lld\n",1ll*r*res+1ll*b*(n-res));
	for(int i=1;i<=n;i++){
		if(cap[eid[i]]){
			if(rv) putchar('b');
			else putchar('r');
		} else {
			if(rv) putchar('r');
			else putchar('b');
		}
	}
	return 0;
}
/*
1 5
1 1
1 1
1 1 1
1 2 0
2 1 0
2 2 1
2 3 1
*/