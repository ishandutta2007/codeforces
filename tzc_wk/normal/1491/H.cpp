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
const int SQRT=316; 
int n,qu,fa[MAXN+5],pre[MAXN+5];
int blk_sz,blk,L[SQRT+5],R[SQRT+5],bel[MAXN+5];
int tag[SQRT+5],sum[SQRT+5];
void update(int x){
	for(int i=L[x];i<=R[x];i++) fa[i]=max(1,fa[i]-tag[x]);
	tag[x]=0;
	for(int i=L[x];i<=R[x];i++){
		if(fa[i]<L[x]) pre[i]=fa[i];
		else pre[i]=pre[fa[i]];
	}
}
int getpre(int x){return max(pre[x]-tag[bel[x]],1);}
int getfa(int x){return max(fa[x]-tag[bel[x]],1);}
void modify(int l,int r,int x){
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++) fa[i]=max(1,fa[i]-x);
		update(bel[l]);return;
	}
	for(int i=l;i<=R[bel[l]];i++) fa[i]=max(1,fa[i]-x);
	for(int i=L[bel[r]];i<=r;i++) fa[i]=max(1,fa[i]-x);
	update(bel[l]);update(bel[r]);
	for(int i=bel[l]+1;i<=bel[r]-1;i++){
		tag[i]=min(n,tag[i]+x);sum[i]++;
		if(sum[i]<=R[i]-L[i]+1) update(i);
	}
}
int getlca(int u,int v){
	while(u!=v){
		if(bel[u]<bel[v]) swap(u,v);
		if(bel[u]>bel[v]) u=getpre(u);
		else{
			if(getpre(u)==getpre(v)){
				while(u!=v){
					if(u<v) swap(u,v);
					u=getfa(u);
				}
			} else {
				u=getpre(u);v=getpre(v);
			}
		}
	} return u;
}
int main(){
	scanf("%d%d",&n,&qu);blk_sz=(int)pow(n,0.5);blk=(n-1)/blk_sz+1;
	for(int i=1;i<=blk;i++){
		L[i]=(i-1)*blk_sz+1;R[i]=min(i*blk_sz,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	for(int i=2;i<=n;i++) scanf("%d",&fa[i]);
	for(int i=1;i<=blk;i++) update(i);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){int l,r,x;scanf("%d%d%d",&l,&r,&x);modify(l,r,x);}
		else{int u,v;scanf("%d%d",&u,&v);printf("%d\n",getlca(u,v));}
	}
	return 0;
}