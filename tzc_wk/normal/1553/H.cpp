//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1<<20;
const int INF=0x3f3f3f3f;
int n,k,cnt[MAXN+5];
struct node{
	int fst,lst,len,ans;
	node(){fst=lst=len=ans=0;}
	node(int x){
		len=1;ans=INF;if(x) fst=lst=0;
		else fst=INF,lst=-INF;
	}
	node operator +(const node &rhs){
		node res;
		res.len=len+rhs.len;
		res.fst=min(fst,rhs.fst+len);
		res.lst=max(lst,rhs.lst+len);
		res.ans=min(min(ans,rhs.ans),rhs.fst+len-lst);
		return res;
	}
};
vector<node> s[MAXN+5];
void build(int k,int l,int r){
	s[k].resize(r-l+1);if(l==r) return s[k][0]=node(cnt[l]),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	for(int i=0;i<mid-l+1;i++){
		s[k][i]=s[k<<1][i]+s[k<<1|1][i];
		s[k][i+(mid-l+1)]=s[k<<1|1][i]+s[k<<1][i];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x]++;build(1,0,(1<<k)-1);
	for(int i=0;i<(1<<k);i++) printf("%d%c",s[1][i].ans," \n"[i==(1<<k)-1]);
	return 0;
}