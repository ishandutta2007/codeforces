//Created time: 2022/3/13 17:20:42
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=5e5;
int n;
struct segtree1{
	struct node{int l,r,mn,lz;} s[MAXN*4+5];
	void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return s[k].mn=l,void();
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void tag(int k,int v){s[k].mn+=v;s[k].lz+=v;}
	void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
	void modify(int k,int l,int r,int v){
		if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,v);
		else if(l>mid) modify(k<<1|1,l,r,v);
		else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
		pushup(k);
	}
	int walk(int k){
		if(s[k].l==s[k].r) return s[k].l;pushdown(k);
		if(s[k<<1|1].mn<=0) return walk(k<<1|1);
		else return walk(k<<1);
	}
} S1;
struct segtree2{
	struct node{int l,r,mn,lz;} s[MAXN*8+5];
	void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return s[k].mn=l,void();
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void tag(int k,int v){s[k].mn+=v;s[k].lz+=v;}
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
	int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} S2;
int main(){
	S1.build(1,-MAXN,0);S2.build(1,-MAXN,MAXN);
	scanf("%d",&n);
	while(n--){
		int x;scanf("%d",&x);S2.modify(1,-MAXN,x-1,1);
		if(x<=0) S1.modify(1,x,0,1);int pos=S1.walk(1);
		printf("%d\n",S2.query(1,pos,MAXN));
	}
	return 0;
}