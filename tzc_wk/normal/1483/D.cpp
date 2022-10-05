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
const int MAXN=600;
int n,m,q;
ll cst[MAXN+5][MAXN+5],a[MAXN+5][MAXN+5];
ll dis[MAXN+5][MAXN+5],t[MAXN+5][MAXN+5],mn[MAXN+5][MAXN+5];
int main(){
	scanf("%d%d",&n,&m);
	memset(cst,63,sizeof(cst));memset(t,63,sizeof(t));
	memset(dis,63,sizeof(dis));memset(mn,63,sizeof(mn));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		cst[u][v]=dis[u][v]=dis[v][u]=w;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	scanf("%d",&q);
	for(int i=1,u,v,w;i<=q;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	for(int v=1;v<=n;v++) for(int x=1;x<=n;x++) for(int y=1;y<=n;y++)
		chkmin(t[v][x],dis[v][y]-a[x][y]);
//	for(int v=1;v<=n;v++) for(int x=1;x<=n;x++){
//		printf("%d %d %lld\n",v,x,t[v][x]);
//	}
	for(int x=1;x<=n;x++) for(int u=1;u<=n;u++) for(int v=1;v<=n;v++){
		chkmin(mn[u][v],dis[x][u]+t[v][x]);
	}
//	for(int u=1;u<=n;u++) for(int v=1;v<=n;v++) for(int x=1;x<=n;x++) for(int y=1;y<=n;y++)
//		chkmin(mn[u][v],dis[x][u]+dis[v][y]-a[x][y]);
	int ans=0;
//	printf("%lld\n",mn[1][4]);
	for(int u=1;u<=n;u++) for(int v=1;v<=n;v++){
		if(mn[u][v]<=-cst[u][v]||mn[v][u]<=-cst[u][v]) ans++;
	} printf("%d\n",ans);
	return 0;
}