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
const int MAXN=3e4;
const int SQRT=sqrt(30000);
int n,mod,qu,a[MAXN+5],key[MAXN+5],uni[MAXN+5],num=0;
struct mat{
	int a[2][2];
	mat(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	mat operator +(const mat &rhs){
		mat res;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) res.a[i][j]=(a[i][j]+rhs.a[i][j])%mod;
		return res;
	}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			for(int k=0;k<2;k++) res.a[i][j]+=a[i][k]*rhs.a[k][j];
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) res.a[i][j]%=mod;
		return res;
	}
	mat operator *(int v){
		mat res;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			res.a[i][j]=a[i][j]*v%mod;
		return res;
	}
} f1,f2,f0;
struct node{int l,r;mat mul,sum;} s[MAXN*4+5];
void pushup(int k){
	s[k].mul=s[k<<1].mul*s[k<<1|1].mul;
	s[k].sum=s[k<<1].sum+s[k<<1].mul*s[k<<1|1].sum;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mul=f2;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int p,int x){
	if(s[k].l==s[k].r){
		if(x) s[k].mul=f1,s[k].sum=f1*(uni[p]%mod);
		else s[k].mul=f2,s[k].sum=f0;
		return;
	} int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,x):modify(k<<1|1,p,x);
	pushup(k);
}
int blk,blk_cnt,bel[MAXN+5],L[SQRT+5],R[SQRT+5];
int cnt[MAXN+5],ans[MAXN+5];
struct query{
	int l,r,id;
	bool operator <(const query &rhs){
		if(bel[l]^bel[rhs.l]) return bel[l]<bel[rhs.l];
		else if(bel[l]&1) return r<rhs.r;
		else return r>rhs.r;
	}
} q[MAXN+5];
void push(int x){cnt[a[x]]++;if(cnt[a[x]]==1) modify(1,a[x],1);}
void pop(int x){cnt[a[x]]--;if(cnt[a[x]]==0) modify(1,a[x],0);}
int main(){
//	freopen("C:\\Users\\\\Documents\\in.txt","r",stdin);
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];
	sort(key+1,key+n+1);key[0]=-1;
	for(int i=1;i<=n;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
	f1.a[0][1]=f1.a[1][0]=f1.a[1][1]=f2.a[0][0]=f2.a[1][1]=1;
	build(1,1,num);blk=(int)pow(n,0.5);blk_cnt=(n-1)/blk+1;
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk+1;R[i]=min(i*blk,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	} scanf("%d",&qu);
	for(int i=1;i<=qu;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+qu+1);int cl=1,cr=0;
	for(int i=1;i<=qu;i++){
		while(cr<q[i].r) push(++cr);
		while(cl>q[i].l) push(--cl);
		while(cr>q[i].r) pop(cr--);
		while(cl<q[i].l) pop(cl++);
		ans[q[i].id]=s[1].sum.a[0][1];
	} for(int i=1;i<=qu;i++) printf("%d\n",ans[i]);
	return 0;
}