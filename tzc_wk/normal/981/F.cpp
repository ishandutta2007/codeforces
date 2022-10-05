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
const int INF=0x3f3f3f3f;
int n,l;ll a[MAXN*2+5],b[MAXN*4+5];
bool check(int mid){
	int L=0,R=0,mx=-INF;
	for(int i=1;i<=2*n;i++){
		while(L<=4*n&&b[L]<a[i]-mid) L++;
		while(R<=4*n&&b[R]<=a[i]+mid) R++;
		mx=max(mx,L-i);if(R-i-1<mx) return 0;
	} return 1;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i]+=l,a[i+n]=a[i]+l;
	for(int i=1;i<=3*n;i++) b[i+n]=b[i]+l;
	int L=0,R=l,p=0;
	while(L<=R){
		int mid=L+R>>1;
		if(check(mid)) p=mid,R=mid-1;
		else L=mid+1;
	} printf("%d\n",p);
	return 0;
}