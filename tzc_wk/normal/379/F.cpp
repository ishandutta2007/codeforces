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
const int MAXQ=5e5;
const int LOG_N=20;
int qu,n=4,a[MAXQ+5],hd[MAXQ*2+10],nxt[MAXQ*2+10],to[MAXQ*2+10],ec=0;
int dep[MAXQ*2+10],fa[MAXQ*2+10][LOG_N+2];
int getlca(int x,int y){
	if(dep[x]<dep[y]) x^=y^=x^=y;
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int getdis(int x,int y){return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);}
int main(){
	scanf("%d",&qu);dep[2]=dep[3]=dep[4]=1;
	for(int i=1;i<=qu;i++){
		scanf("%d",&a[i]);fa[n+1][0]=fa[n+2][0]=a[i];
		dep[n+1]=dep[n+2]=dep[a[i]]+1;n+=2;
	}
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int u=2,v=3,len=2;
	for(int i=1;i<=qu;i++){
		int lu=getdis(i*2+3,u),lv=getdis(i*2+3,v);
		if(lu<lv) swap(lu,lv),swap(u,v);
		if(lu>len) len=lu,v=i*2+3;
		printf("%d\n",len);
	}
	return 0;
}