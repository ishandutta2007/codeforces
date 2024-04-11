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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5000;
const int MAXP=5e6;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,cnt[MAXN+5],w[MAXP+5],pt[MAXN+5];
int hd[MAXP+5],nxt[MAXP*2+5],val[MAXP*2+5],to[MAXP*2+5],ec=0;
void adde(int u,int v,int w){/*printf("%d %d %d\n",u,v,w);*/to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int ncnt=1,pr[MAXN+5],prcnt=0,vis[MAXN+5],mxp[MAXN+5],ps[MAXN+5],tmp[MAXN+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;if(i%pr[j]==0) break;
		}
	}
}
int calc(int n,int p){return (!n)?0:(n/p+calc(n/p,p));}
int siz[MAXP+5];ll smd[MAXP+5],sm_out[MAXP+5];
void dfs1(int x,int f){
	siz[x]=w[x];
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		dfs1(y,x);siz[x]+=siz[y];
		smd[x]+=smd[y]+1ll*siz[y]*z;
	} //printf("%d %lld %d\n",x,smd[x],siz[x]);
}
void dfs2(int x,int f){
	ll sum=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];
		if(y==f) sum+=sm_out[x];
		else sum+=smd[y]+1ll*siz[y]*z;
	}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		sum-=smd[y]+1ll*siz[y]*z;sm_out[y]=sum+1ll*(n-siz[y])*z;
		sum+=smd[y]+1ll*siz[y]*z;dfs2(y,x);
	}
}
int main(){
	scanf("%d",&n);sieve(MAXN);
	for(int i=1,k;i<=n;i++) scanf("%d",&k),cnt[k]++;
	w[1]=cnt[1];pt[1]=1;
	for(int i=2;i<=MAXN;i++) for(int j=1;j<=prcnt;j++)
		if(i%pr[j]==0) mxp[i]=j;
	ps[0]=1;
	for(int i=2;i<=MAXN;i++){
		++ncnt;pt[i]=ncnt;w[ncnt]=cnt[i];tmp[0]=ncnt;
//		printf("%d\n",pt[i]);
//		printf("%d\n",ps[1]);
		for(int j=1;j<=prcnt;j++){
			int c=calc(i,pr[j]);
			if(j<mxp[i]){
				++ncnt;
				adde(ncnt-1,ncnt,c);
				adde(ncnt,ncnt-1,c);
				tmp[j]=ncnt;
			} else if(j==mxp[i]){
				adde(ps[j-1],ncnt,calc(i,pr[j])-calc(i-1,pr[j]));
				adde(ncnt,ps[j-1],calc(i,pr[j])-calc(i-1,pr[j]));
				for(int k=0;k<j;k++) ps[k]=tmp[k];
			} if(j==prcnt||pr[j+1]>i){
				ps[j]=1;break;
			}
		}
	} dfs1(1,0);dfs2(1,0);ll mn=INF;
	for(int i=1;i<=ncnt;i++) chkmin(mn,smd[i]+sm_out[i]);
	printf("%lld\n",mn);
	return 0;
}