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
#define y1 y11111111
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
int n,a[25],sum[1<<20];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=-a[i];
	n<<=1;
	for(int i=1;i<(1<<n);i++) sum[i]=sum[i&(i-1)]+a[32-__builtin_clz(i&(-i))];
	for(int i=1;i<=n;i++){
		if(!a[i]) return puts("YES"),void();
		int rst=((1<<n)-1)^(1<<i-1)^(1<<((i>(n>>1))?(i-(n>>1)-1):(i+(n>>1)-1)));
		for(int j=rst;j;j=(j-1)&rst){
			if(a[i]==sum[j]||-a[i]==sum[j]) return puts("YES"),void();
		}
	} puts("NO");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
    return 0;
}