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
const int MAXN=1e4;
int n,qu;
struct node{int l,r;vector<int> v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int l,int r,int v){
	if(l<=s[k].l&&s[k].r<=r){s[k].v.pb(v);return;}
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
}
bitset<MAXN+5> cur,ans;
void iterate(int k){
	bitset<MAXN+5> tmp=cur;
	for(int i=0;i<s[k].v.size();i++) cur=cur|(cur<<s[k].v[i]);
	ans|=cur;if(s[k].l^s[k].r) iterate(k<<1),iterate(k<<1|1);
	cur=tmp;
}
int main(){
	scanf("%d%d",&n,&qu);build(1,1,n);
	for(int i=1,l,r,v;i<=qu;i++) scanf("%d%d%d",&l,&r,&v),modify(1,l,r,v);
	cur[0]=1;iterate(1);int cnt=0;
	for(int i=1;i<=n;i++) if(ans[i]) cnt++;
	printf("%d\n",cnt);for(int i=1;i<=n;i++) if(ans[i]) printf("%d ",i);
	return 0;
}