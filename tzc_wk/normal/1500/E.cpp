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
const int MAXN=2e5;
int n,qu,cnt=0,num=0;
ll key[MAXN*2+5],uni[MAXN*2+5],a[MAXN+5],tot=0;
struct event{int opt;ll x;} q[MAXN+5];
struct node{int l,r,cnt;ll sum,sum_i;} s[MAXN*8+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushup(int k){
	s[k].cnt=s[k<<1].cnt+s[k<<1|1].cnt;s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	s[k].sum_i=s[k<<1].sum_i+s[k<<1|1].sum_i+s[k<<1|1].sum*s[k<<1].cnt;
}
void modify(int k,int p,int x){
	if(s[k].l==s[k].r){
		s[k].cnt+=x;s[k].sum+=x*uni[p];
		s[k].sum_i=1ll*s[k].cnt*(s[k].cnt+1)/2*uni[p];
		return;
	} int mid=s[k].l+s[k].r>>1;
	if(p<=mid) modify(k<<1,p,x);
	else modify(k<<1|1,p,x);
	pushup(k);
}
pair<ll,ll> getxth(int k,int x){
	if(s[k].l==s[k].r){return mp(1ll*x*uni[s[k].l],1ll*x*(x+1)/2*uni[s[k].l]);}
	if(x<=s[k<<1].cnt) return getxth(k<<1,x);
	else{
		pair<ll,ll> ss=getxth(k<<1|1,x-s[k<<1].cnt);
		return mp(ss.fi+s[k<<1].sum,ss.se+s[k<<1].sum_i+ss.fi*s[k<<1].cnt);
	}
}
ll getf(int k){
	pair<ll,ll> s1=getxth(1,k+1),s2=getxth(1,n-k);
	return s1.fi-(s[1].sum-s2.fi);
}
ll getans(){
	if(!n) return 0;
	int l=0,r=(n-1)/2,p=(n-1)/2+1;
	while(l<=r){
		int mid=l+r>>1;
		if(getf(mid)<=0) p=mid,r=mid-1;
		else l=mid+1;
	} p--;//printf("%d\n",p);
	pair<ll,ll> s1=getxth(1,p+1),s2=getxth(1,n-p);
	s2.fi=s[1].sum-s2.fi;s2.se=s[1].sum_i-s2.se;
//	printf("%lld %lld %lld %lld\n",s1.fi,s1.se,s2.fi,s2.se);
	ll sum=s1.fi*(p+2)-s1.se-s2.se+s2.fi*(n-p);
	sum=sum*2;if((n&1)) sum-=max(getf((n-1)/2),0ll);
	return tot-sum;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),key[++cnt]=a[i],tot+=a[i];
	for(int i=1;i<=qu;i++){scanf("%d%lld",&q[i].opt,&q[i].x);key[++cnt]=q[i].x;}
	sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
	for(int i=1;i<=qu;i++) q[i].x=lower_bound(uni+1,uni+num+1,q[i].x)-uni;
	build(1,1,num);for(int i=1;i<=n;i++) modify(1,a[i],1);
	printf("%lld\n",getans());
	for(int i=1;i<=qu;i++){
		if(q[i].opt==1) modify(1,q[i].x,1),++n,tot+=uni[q[i].x];
		else modify(1,q[i].x,-1),--n,tot-=uni[q[i].x];
		printf("%lld\n",getans());
	}
	return 0;
}