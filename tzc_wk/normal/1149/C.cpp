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
int n,qu;char str[MAXN+5];
struct node{int l,r,sum,lmx,rmx,lmn,rmn,mx1,mx2,mx;} s[MAXN*4+5];
void pushup(int k){
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	s[k].lmx=max(s[k<<1].lmx,s[k<<1].sum+s[k<<1|1].lmx);
	s[k].lmn=min(s[k<<1].lmn,s[k<<1].sum+s[k<<1|1].lmn);
	s[k].rmx=max(s[k<<1|1].rmx,s[k<<1|1].sum+s[k<<1].rmx);
	s[k].rmn=min(s[k<<1|1].rmn,s[k<<1|1].sum+s[k<<1].rmn);
	s[k].mx1=max(s[k<<1].mx1,max(-s[k<<1].sum+s[k<<1|1].mx1,s[k<<1|1].lmx+s[k<<1].rmx*2-s[k<<1].sum));
	s[k].mx2=max(s[k<<1|1].mx2,max(s[k<<1|1].sum+s[k<<1].mx2,-s[k<<1].rmn+s[k<<1|1].sum-2*s[k<<1|1].lmn));
	s[k].mx=max(max(s[k<<1].mx,s[k<<1|1].mx),max(s[k<<1].mx2+s[k<<1|1].lmx,-s[k<<1].rmn+s[k<<1|1].mx1));
}
void build(int k=1,int l=1,int r=n){
	s[k].l=l;s[k].r=r;
	if(l==r){
		if(str[l]=='(') s[k].sum=1,s[k].lmx=1,s[k].rmx=1,s[k].lmn=0,s[k].rmn=0;
		else s[k].sum=-1,s[k].lmx=0,s[k].rmx=0,s[k].lmn=-1,s[k].rmn=-1;
		s[k].mx1=1;s[k].mx2=1;s[k].mx=1;return;
	} int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void modify(int k,int p,int v){
	if(s[k].l==s[k].r){
		s[k].lmx=s[k].rmx=max(v,0);
		s[k].lmn=s[k].rmn=min(v,0);
		s[k].sum=v;
		s[k].mx1=1;s[k].mx2=1;s[k].mx=1;return;
	} int mid=s[k].l+s[k].r>>1;
	if(p<=mid) modify(k<<1,p,v);
	else modify(k<<1|1,p,v);
	pushup(k);
}
int main(){
	scanf("%d%d%s",&n,&qu,str+1);n=(n-1)<<1;
	build(1,1,n);printf("%d\n",s[1].mx);
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);
		if(str[x]!=str[y]){
			swap(str[x],str[y]);
			modify(1,x,(str[x]=='(')?1:-1);
			modify(1,y,(str[y]=='(')?1:-1);
		} printf("%d\n",s[1].mx);
	}
	return 0;
}