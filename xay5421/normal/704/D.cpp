#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005,INF=0X3F3F3F3F;
int n,m,r,b,x[N],y[N],xx[N],yy[N];
int cnt[N*2],d[N*2],lim[N*2];
int s,t,S,T;
int dep[N*2],gap[N*2];
int pp=1,lnk[N*2],cur[N*2],nxt[N*20],to[N*20],we[N*20];
bool ban[N*20];
char ans[N];
void ae(int k1,int k2,int k3){
	//if(!k3)return;
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,we[pp]=0 ,nxt[pp]=lnk[k2],lnk[k2]=pp;
}
void jb(int k1,int k2,int k3,int k4){
	lim[k2]+=k3,lim[k1]-=k3;
	D("jb %d %d %d %d\n",k1,k2,k3,k4);
	ae(k1,k2,k4-k3);
}
int ed;
int sap(int k1,int k2){
	if(k1==ed)return k2;
	int k3=k2;
	for(int&i=cur[k1];i;i=nxt[i])if(!ban[i]&&we[i]&&dep[k1]==dep[to[i]]+1){
		int f=sap(to[i],min(k3,we[i]));
		we[i]-=f,we[i^1]+=f,k3-=f;
		if(!k3)return k2;
	}
	if(!--gap[dep[k1]++])dep[ed]=T+1;
	++gap[dep[k1]],cur[k1]=lnk[k1];
	return k2-k3;
}
int work(int beg,int ed){
	::ed=ed;
	memcpy(cur,lnk,sizeof(cur));
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	gap[0]=T;
	int res=0;
	while(dep[ed]<=T){
		res+=sap(beg,INF);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&r,&b);
	rep(i,1,n){
		scanf("%d%d",x+i,y+i);
		xx[++*xx]=x[i],yy[++*yy]=y[i];
	}
	
	sort(xx+1,xx+1+*xx);
	*xx=unique(xx+1,xx+1+*xx)-xx-1;
	rep(i,1,n)x[i]=lower_bound(xx+1,xx+1+*xx,x[i])-xx;
	
	sort(yy+1,yy+1+*yy);
	*yy=unique(yy+1,yy+1+*yy)-yy-1;
	rep(i,1,n)y[i]=lower_bound(yy+1,yy+1+*yy,y[i])-yy;
	
	rep(i,1,n)++cnt[x[i]],++cnt[y[i]+*xx];
	
	s=*xx+*yy+1,t=s+1,S=t+1,T=S+1;
	
	memset(d,63,sizeof(d));
	rep(i,1,m){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		if(k1==1){
			int j=lower_bound(xx+1,xx+1+*xx,k2)-xx;
			if(xx[j]==k2)d[j]=min(d[j],k3);
		}else{
			int j=lower_bound(yy+1,yy+1+*yy,k2)-yy;
			if(yy[j]==k2)d[j+*xx]=min(d[j+*xx],k3);
		}
	}
	
	rep(i,1,n)jb(x[i],y[i]+*xx,0,1);
	rep(i,1,*xx){
		int lb=max(0,(cnt[i]-d[i]+1)/2);
		int rb=min(cnt[i],(cnt[i]+d[i])/2);
		if(lb>rb){
			puts("-1");
			return 0;
		}
		jb(s,i,lb,rb);
	}
	rep(i,*xx+1,*xx+*yy){
		int lb=max(0,(cnt[i]-d[i]+1)/2);
		int rb=min(cnt[i],(cnt[i]+d[i])/2);
		if(lb>rb){
			puts("-1");
			return 0;
		}
		jb(i,t,lb,rb);
	}
	int sum=0;
	rep(i,1,*xx+*yy+2){
		if(lim[i]>0)ae(S,i,lim[i]),sum+=lim[i];
		if(lim[i]<0)ae(i,T,-lim[i]);
	}
	
	ae(t,s,INF);
	int f1=work(S,T);
	D("need=%d f1=%d\n",sum,f1);
	if(sum!=f1){
		puts("-1");
		return 0;
	}
	for(int i=lnk[S];i;i=nxt[i])ban[i]=ban[i^1]=1;
	for(int i=lnk[T];i;i=nxt[i])ban[i]=ban[i^1]=1;
	ban[pp]=ban[pp^1]=1;
	int f2=work(s,t);
	
	int rc='r',bc='b';
	if(b<r){
		swap(rc,bc);
		swap(r,b);
	}
	LL res=0;
	rep(i,1,n){
		ans[i]=(we[i*2]==0?rc:bc);
		if(we[i*2]==0)res+=r;
		else res+=b;
	}
	printf("%lld\n",res);
	puts(ans+1);
	return 0;
}