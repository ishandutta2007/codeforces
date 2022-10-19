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
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
struct city{
	int a,c,pos;
	bool operator <(const city &rhs){
		return a<rhs.a;
	}
} a[MAXN+5];
struct segtree{
	struct node{int l,r;ll mn;} s[MAXN*4+5];
	void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void modify(int k,int p,ll x){
		if(s[k].l==s[k].r){s[k].mn=x;return;}
		int mid=s[k].l+s[k].r>>1;
		if(p<=mid) modify(k<<1,p,x);
		else modify(k<<1|1,p,x);
		pushup(k);
	}
	ll query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
		int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} st[2];
ll dp[MAXN+5];
vector<int> pp[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].a,&a[i].c);
	sort(a+1,a+n+1);st[0].build(1,1,n);st[1].build(1,1,n);
//	for(int i=1;i<=n;i++) printf("%d %d\n",a[i].a,a[i].c);
	for(int i=1;i<=n;i++){
		int l=i,r=n,p=n+1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid].a<=a[i].a+a[i].c) l=mid+1;
			else p=mid,r=mid-1;
		} a[i].pos=p;
//		printf("%d %d\n",i,a[i].pos);
		pp[a[i].pos].pb(i);
	}
	for(int i=2;i<=n;i++){
		for(int u:pp[i]){
			st[0].modify(1,u,INF);
			st[1].modify(1,u,dp[u]-a[u].a-a[u].c);
		}
		dp[i]=min(st[0].query(1,1,i-1),st[1].query(1,1,i-1)+a[i].a);
		st[0].modify(1,i,dp[i]);
//		printf("%d %lld\n",i,dp[i]);
	} ll sum=dp[n];
	for(int i=1;i<=n;i++) sum+=a[i].c;
	printf("%lld\n",sum);
	return 0;
}