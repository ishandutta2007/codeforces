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
const int MAXN=4e5;
int n,qu,key[MAXN*2+5],uni[MAXN*2+5],num=0,cnt=0;
int a[MAXN+5],x[MAXN+5],y[MAXN+5];
int v[MAXN+5],nxt[MAXN+5],hd[MAXN+5],item_n=0;
void ins(int p,int q){v[++item_n]=q;nxt[item_n]=hd[p];hd[p]=item_n;}
int getnum(int x){
	int l=1,r=num;
	while(l<=r){
		int mid=(l+r)>>1;
		if(uni[mid]==x) return mid;
		if(uni[mid]<x) l=mid+1;
		else r=mid-1;
	}
}
int f[MAXN+5],g[MAXN+5],qf[MAXN+5],qg[MAXN+5],c[MAXN+5];
int t[MAXN*2+5];
void add(int x,int v){for(int i=x;i<=num;i+=(i&(-i))) chkmax(t[i],v);}
int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) chkmax(ret,t[i]);return ret;}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[++cnt]=a[i];
	for(int i=1;i<=qu;i++) scanf("%d%d",&x[i],&y[i]),ins(x[i],i),key[++cnt]=y[i];
	sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=getnum(a[i]);
	for(int i=1;i<=qu;i++) y[i]=getnum(y[i]);
	for(int i=1;i<=n;i++) f[i]=query(a[i]-1)+1,add(a[i],f[i]);
	memset(t,0,sizeof(t));
	for(int i=n;i;i--) g[i]=query(num-a[i])+1,add(num-a[i]+1,g[i]);
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		for(int e=hd[i];e;e=nxt[e]){
			int id=v[e];qf[id]=query(y[id]-1)+1;
		} add(a[i],f[i]);
	}
	memset(t,0,sizeof(t));
	for(int i=n;i;i--){
		for(int e=hd[i];e;e=nxt[e]){
			int id=v[e];qg[id]=query(num-y[id])+1;
		} add(num-a[i]+1,g[i]);
	}
	int mx=0;
	for(int i=1;i<=n;i++) chkmax(mx,f[i]+g[i]-1);
	for(int i=1;i<=n;i++) if(f[i]+g[i]-1==mx) c[f[i]]++;
	for(int i=1;i<=qu;i++){
		if(qf[i]+qg[i]-1>mx) printf("%d\n",qf[i]+qg[i]-1);
		else if(qf[i]+qg[i]-1<mx&&f[x[i]]+g[x[i]]-1==mx&&c[f[x[i]]]==1) printf("%d\n",mx-1);
		else printf("%d\n",mx);
	}
	return 0;
}