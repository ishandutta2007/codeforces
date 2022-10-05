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
const int MAXN=1e5;
int n,a[MAXN+5];
int Rand(){return rand()<<15|rand();}
struct node{int ch[2],key,siz;ll val,sum,lz;} s[MAXN+5];
int rt=0,ncnt=0;
void pushup(int k){
	s[k].siz=s[s[k].ch[0]].siz+s[s[k].ch[1]].siz+1;
	s[k].sum=s[s[k].ch[0]].sum+s[s[k].ch[1]].sum+s[k].val;
}
void tag(int k,ll v){s[k].val+=v;s[k].lz+=v;s[k].sum+=1ll*s[k].siz*v;}
void pushdown(int k){
	if(s[k].lz){
		if(s[k].ch[0]) tag(s[k].ch[0],s[k].lz);
		if(s[k].ch[1]) tag(s[k].ch[1],s[k].lz);
		s[k].lz=0;
	}
}
void split(int k,int sz,int &a,int &b){
	if(!k) return a=b=0,void();pushdown(k);
	if(sz<=s[s[k].ch[0]].siz) b=k,split(s[k].ch[0],sz,a,s[k].ch[0]),pushup(k);
	else a=k,split(s[k].ch[1],sz-s[s[k].ch[0]].siz-1,s[k].ch[1],b),pushup(k);
}
int merge(int a,int b){
	if(!a||!b) return a+b;pushdown(a);pushdown(b);
	if(s[a].key<s[b].key) return s[a].ch[1]=merge(s[a].ch[1],b),pushup(a),a;
	else return s[b].ch[0]=merge(a,s[b].ch[0]),pushup(b),b;
}
void insert(int p,ll v,int d){
	int k1,k2;split(rt,p,k1,k2);s[++ncnt].key=Rand();s[ncnt].val=v;s[ncnt].sum=v;
	s[ncnt].siz=1;if(k2) tag(k2,d);rt=merge(merge(k1,ncnt),k2);
}
ll query(int x){
	int k1,k2;split(rt,x+1,k1,k2);ll res=s[k1].sum;
	return rt=merge(k1,k2),res;
}
int main(){
	srand(187518437);scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	insert(0,0,0);
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,p=i;
		while(l<=r){
			int mid=l+r>>1;
			if(query(mid)<query(mid-1)+1ll*a[i]*mid) p=mid,r=mid-1;
			else l=mid+1;
		} insert(p,1ll*a[i]*p,a[i]);
//		printf("%d\n",p);
//		for(int j=0;j<=i;j++) printf("%lld%c",query(j)," \n"[j==i]);
	} ll res=0;
	for(int i=0;i<=n;i++) chkmax(res,query(i));
	printf("%lld\n",res);
	return 0;
}