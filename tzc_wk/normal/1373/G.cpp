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
const int MAXN=4e5;
int n,k,qu,cnt[MAXN+5];
map<int,bool> vis[MAXN+5];
struct node{int l,r,val,lz;} s[MAXN*4+5];
void pushup(int k){s[k].val=max(s[k<<1].val,s[k<<1|1].val);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].val=l,void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void tag(int k,int v){s[k].lz+=v;s[k].val+=v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int main(){
	scanf("%d%d%d",&n,&k,&qu);multiset<int> st;
	build(1,1,MAXN);
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);
		if(!vis[x][y]){
			vis[x][y]=1;int pos=y+abs(x-k);
			st.insert(pos);
			modify(1,1,pos,1);
		} else {
			vis[x][y]=0;int pos=y+abs(x-k);
			st.erase(st.find(pos));
			modify(1,1,pos,-1);
		}
		if(st.empty()) puts("0");
		else printf("%d\n",max(query(1,1,(*st.rbegin()))-1,n)-n);
	}
	return 0;
}//