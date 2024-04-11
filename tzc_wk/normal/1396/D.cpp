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
const int MAXN=2000;
const int MOD=1e9+7;
int n,k,L,x[MAXN+5],y[MAXN+5],c[MAXN+5];
int kx[MAXN+5],ky[MAXN+5],ux[MAXN+5],uy[MAXN+5],nx,ny;
vector<int> px[MAXN+5],py[MAXN+5];
int pos[MAXN+5],res=0;
struct node{int l,r,val,sm,lz,rit;} s[MAXN*4+5];
multiset<int> occ[MAXN+5];
void pushup(int k){
	s[k].val=(s[k<<1].val+s[k<<1|1].val)%MOD;
	s[k].rit=s[k<<1|1].rit;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].sm=uy[l]-uy[l-1],void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	s[k].sm=(s[k<<1].sm+s[k<<1|1].sm)%MOD;
}
void tag(int k,int v){s[k].val=1ll*s[k].sm*v%MOD;s[k].lz=s[k].rit=v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
int walk(int k,int v){//find the leftmost position >v
	if(s[k].l==s[k].r) return (s[k].rit>v)?s[k].l:(s[k].l+1);
	pushdown(k);
	if(s[k<<1].rit>v) return walk(k<<1,v);
	else return walk(k<<1|1,v);
}
int query(){return s[1].val;}
void makemax(int l,int r,int v){
//	printf("makemax %d %d %d\n",l,r,v);
	if(l>r) return;int p=walk(1,v)-1;
	chkmin(p,r);modify(1,l,p,v);
}
int main(){
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		++x[i];++y[i];kx[i]=x[i];ky[i]=y[i];
	} sort(kx+1,kx+n+1);sort(ky+1,ky+n+1);
	for(int i=1;i<=n;i++) if(kx[i]^kx[i-1]) ux[++nx]=kx[i];
	for(int i=1;i<=n;i++) if(ky[i]^ky[i-1]) uy[++ny]=ky[i];
	for(int i=1;i<=n;i++){
		x[i]=lower_bound(ux+1,ux+nx+1,x[i])-ux;
		y[i]=lower_bound(uy+1,uy+ny+1,y[i])-uy;
		px[x[i]].pb(i);py[y[i]].pb(i);
	} ux[nx+1]=uy[ny+1]=L+1;build(1,1,ny);
	for(int i=1;i<=k;i++) occ[i].insert(0),occ[i].insert(ny+1);
	for(int i=1;i<=nx;i++){
		multiset<int> st;
		for(int j=1;j<=k;j++) pos[j]=ny+1,st.insert(ny+1);
		for(int j=ny;j;j--){
			for(int id:py[j]) if(x[id]>=i){
				st.erase(st.find(pos[c[id]]));
				pos[c[id]]=j;st.insert(pos[c[id]]);
				occ[c[id]].insert(j);
			} modify(1,j,j,uy[*st.rbegin()]);
//			printf("%d%c",uy[*st.rbegin()]," \n"[j==1]);
		}
		for(int j=nx;j>=i;j--){
			res=(res+1ll*(ux[i]-ux[i-1])*(ux[j+1]-ux[j])%MOD
			*(1ll*uy[ny]*(L+1)%MOD-query()+MOD))%MOD;
//			printf("%d %d %d\n",i,j,s[1].val);
//			printf("%d\n",1ll*(ux[i]-ux[i-1])*(ux[j+1]-ux[j])%MOD
//			*(1ll*uy[ny]*(L+1)%MOD-s[1].val+MOD)%MOD);
			for(int id:px[j]){
				occ[c[id]].erase(occ[c[id]].find(y[id]));
				int pre=*--occ[c[id]].upper_bound(y[id]);
				int nxt=*occ[c[id]].upper_bound(y[id]);
				makemax(pre+1,y[id],uy[nxt]);
			}
		}
	} printf("%d\n",res);
	return 0;
}