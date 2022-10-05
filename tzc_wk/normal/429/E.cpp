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
const int MAXN=1e5;
int n,l[MAXN+5],r[MAXN+5],key[MAXN*2+5],cnt=0,uni[MAXN*2+5],num=0;
int d[MAXN*2+5],hd[MAXN*2+5],nxt[MAXN*6+5],to[MAXN*6+5],ec=1;
void adde(int u,int v){/*printf("adde %d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dir[MAXN*3+5],vis[MAXN*2+5],now[MAXN*2+5];
void dfs(int x){
//	printf("dfs %d\n",x);
	vis[x]=1;
	for(int &e=now[x];e;e=nxt[e]) if(!~dir[e>>1]){
		dir[e>>1]=e&1;dfs(to[e]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);++r[i];
		key[++cnt]=l[i];key[++cnt]=r[i];
	} sort(key+1,key+cnt+1);key[0]=-1;
	for(int i=1;i<=cnt;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(uni+1,uni+num+1,l[i])-uni;
		r[i]=lower_bound(uni+1,uni+num+1,r[i])-uni;
		d[l[i]]++;d[r[i]]--;adde(l[i],r[i]);adde(r[i],l[i]);
	}
	for(int i=1;i<=num;i++){
		d[i]+=d[i-1];
		if(d[i]&1) adde(i,i+1),adde(i+1,i);
	}
	memset(dir,-1,sizeof(dir));
	for(int i=1;i<=num;i++) now[i]=hd[i];
	for(int i=1;i<=num;i++) if(!vis[i]) dfs(i);
	for(int i=1;i<=n;i++) printf("%d%c",dir[i]," \n"[i==n]);
	return 0;
}