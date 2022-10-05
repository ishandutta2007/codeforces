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
const int MAXP=MAXN<<5;
int n,a[MAXN+5],b[MAXN+5];
struct node{int ch[2],siz;ll sum,sum_mul;} s[MAXP+5];
int rt[MAXN+5],ncnt=0;
void pushup(int k){
	s[k].siz=s[s[k].ch[0]].siz+s[s[k].ch[1]].siz;
	s[k].sum=s[s[k].ch[0]].sum+s[s[k].ch[1]].sum;
	s[k].sum_mul=s[s[k].ch[0]].sum_mul+s[s[k].ch[1]].sum_mul+s[s[k].ch[1]].siz*s[s[k].ch[0]].sum;
}
void insert(int &k,int l,int r,int v){
	if(!k) k=++ncnt;
	if(l==r) return s[k].sum=v,s[k].siz=1,void();
	int mid=l+r>>1;
	if(v<=mid) insert(s[k].ch[0],l,mid,v);
	else insert(s[k].ch[1],mid+1,r,v);
	pushup(k);
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x+y;int mid=l+r>>1,z=++ncnt;
	s[z].ch[0]=merge(s[x].ch[0],s[y].ch[0],l,mid);
	s[z].ch[1]=merge(s[x].ch[1],s[y].ch[1],mid+1,r);
	return pushup(z),z;
}
int f[MAXN+5];ll sm[MAXN+5],res=0;
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool book[MAXN+5];
ll calc(int x){
	assert(book[x]);x=find(x);
//	printf("calc %d %lld %lld %lld\n",x,sm[x],s[rt[x]].sum,s[rt[x]].sum_mul);
	return -sm[x]+x*s[rt[x]].sum+s[rt[x]].sum_mul;
}
void unite(int x,int y){
//	printf("unite %d %d\n",x,y);
//	printf("%lld %lld\n",calc(x),calc(y));
	x=find(x);y=find(y);res-=calc(x);res-=calc(y);
	f[y]=x;sm[x]+=sm[y];rt[x]=merge(rt[x],rt[y],1,MAXN);
	res+=calc(x);//printf("%lld\n",calc(x));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	set<int> can;ll ss=0;
	for(int i=1;i<=MAXN;i++) can.insert(i);
	for(int i=1;i<=n;i++){
		int p=*can.lower_bound(a[i]);
		insert(rt[p],1,n,b[i]);can.erase(can.find(p));
		ss+=1ll*(p-a[i])*b[i];
		sm[p]=1ll*p*b[i];book[p]=1;
		if(book[p+1]) unite(p,p+1);
		if(book[p-1]) unite(p-1,p);
		printf("%lld\n",res+ss);
	}
	return 0;
}