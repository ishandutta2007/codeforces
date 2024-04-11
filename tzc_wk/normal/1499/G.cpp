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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=4e5;
const int MOD=998244353;
int n1,n2,m,mm,pw2[MAXN+5],tag[MAXN+5],f[MAXN+5],res=0,sum[MAXN+5][2];
int find(int x){
	if(!f[x]) return x;if(!f[f[x]]) return f[x];
	int fx=find(f[x]);tag[x]^=tag[f[x]];return f[x]=fx;
}
bool ask(int x){if(!f[x]) return tag[x];int fx=find(x);/*printf("%d %d\n",tag[fx],tag[x]);*/return tag[fx]^tag[x];}
void rev(int x){
//	printf("reverse %d\n",x);
	x=find(x);res=(res-sum[x][tag[x]]+MOD)%MOD;
	tag[x]^=1;res=(res+sum[x][tag[x]])%MOD;
}
void merge(int x,int y){
	x=find(x);y=find(y);if(x==y) return;f[x]=y;
//	printf("merge %d %d\n",x,y);
	res=(res-sum[x][tag[x]]+MOD)%MOD;res=(res-sum[y][tag[y]]+MOD)%MOD;
	sum[y][tag[y]]=(sum[y][tag[y]]+sum[x][tag[x]])%MOD;
	sum[y][tag[y]^1]=(sum[y][tag[y]^1]+sum[x][tag[x]^1])%MOD;
	tag[x]^=tag[y];res=(res+sum[y][tag[y]])%MOD;
}
int con[MAXN+5];
void dealins(int x,int y){
	int id=++mm;sum[id][0]=pw2[id];res=(res+pw2[id])%MOD;
	if(!con[x]&&!con[y]) return con[x]=con[y]=id,void();
//	printf("ins %d %d\n",x,y);
	if(!con[x]) swap(x,y);
	if(!con[y]){
//		printf("%d %d\n",x,y);
		if(!ask(con[x])) rev(id);//printf("%d\n",res);
		merge(id,con[x]);con[x]=0;con[y]=id;
	} else {
		if(ask(con[x])!=ask(con[y])) rev(con[y]);
		if(!ask(con[x])) rev(id);
		merge(id,con[x]);merge(id,con[y]);con[x]=con[y]=0;
	}
}
void prt_color(){
	int cnt=0;
	for(int i=1;i<=mm;i++) if(!ask(i)) cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=mm;i++) if(!ask(i)) printf("%d ",i);
	printf("\n");
}
int main(){
	scanf("%d%d%d",&n1,&n2,&m);
	pw2[0]=1;for(int i=1;i<=MAXN;i++) pw2[i]=(pw2[i-1]<<1)%MOD;
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),dealins(u,v+n1);
	int qu;scanf("%d",&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int u,v;scanf("%d%d",&u,&v);
			dealins(u,v+n1);printf("%d\n",res);
		} else prt_color();
		fflush(stdout);
	}
	return 0;
}
/*
2 2 2
1 1
2 2
2
1 1 2
2
*/