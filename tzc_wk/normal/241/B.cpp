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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e4;
const int LOG_V=30;
const int MAXP=MAXN*31;
const int MOD=1e9+7;
const int INV2=5e8+4;
int n,a[MAXN+5];ll m;
struct node{int ch[2],siz;short cnt[31][2];} s[MAXP+5];
int ncnt,rt;
void insert(int &k,int d,int v){
	if(!k) k=++ncnt;s[k].siz++;
	for(int i=0;i<=LOG_V;i++) s[k].cnt[i][v>>i&1]++;
	if(!~d) return;//printf("%d %d %d\n",k,d,v);
	insert(s[k].ch[v>>d&1],d-1,v);
}
int query(int k,int d,int x,int y){
	if(!k) return 0;if(!~d) return s[k].siz;
	int dx=x>>d&1,dy=y>>d&1;
	if(dy) return query(s[k].ch[dx^1],d-1,x,y);
	else return s[s[k].ch[dx^1]].siz+query(s[k].ch[dx],d-1,x,y);
}
bool check(int mid){
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=query(rt,LOG_V,a[i],mid);
	return sum>=m;
}
int getsum(int k,int d,int x,int y){
	if(!k) return 0;if(!~d) return 1ll*y*s[k].siz%MOD;
	int dx=x>>d&1,dy=y>>d&1;
	if(dy) return getsum(s[k].ch[dx^1],d-1,x,y);
	else{
		int sum=getsum(s[k].ch[dx],d-1,x,y);
		sum=(sum+1ll*(y&~((1<<d+1)-1))*s[s[k].ch[dx^1]].siz)%MOD;
		sum=(sum+1ll*(1<<d)*s[s[k].ch[dx^1]].siz)%MOD;
		for(int i=d-1;~i;i--) sum=(sum+1ll*(1<<i)*(s[s[k].ch[dx^1]].cnt[i][~x>>i&1]))%MOD;
		return sum;
	}
}
int main(){
	scanf("%d%lld",&n,&m);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) insert(rt,LOG_V,a[i]);m<<=1;
	int l=0,r=(1<<30)-1,p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) p=mid,l=mid+1;
		else r=mid-1;
	} int ans=0;ll sum=0;//printf("%d\n",p);
	for(int i=1;i<=n;i++) ans=(ans+getsum(rt,LOG_V,a[i],p))%MOD;
	for(int i=1;i<=n;i++) sum+=query(rt,LOG_V,a[i],p);
	ans=(ans-1ll*(sum-m)*p%MOD+MOD)%MOD;
	printf("%d\n",1ll*ans*INV2%MOD);
	return 0;
}