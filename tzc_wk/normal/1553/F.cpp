#pragma GCC optimize(2)
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
#define y1 y1111111
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
    template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
    template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
    template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
    void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MAXV=3e5;
int n,a[MAXN+5];
struct bitree{
	ll t[MAXV+5];
	void add(int x,ll v){for(int i=x;i<=MAXV;i+=(i&(-i))) t[i]+=v;}
	ll query(int x){ll ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
} t1,t2,t3;
int main(){
    scanf("%d",&n);ll res=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=MAXV;j+=a[i]){
    		ll s=t3.query(min(j+a[i]-1,MAXV))-t3.query(max(j-1,0));
    		int c=t2.query(min(j+a[i]-1,MAXV))-t2.query(max(j-1,0));
    		res+=s-1ll*c*j;
		}
		res+=1ll*(i-1)*a[i]-t1.query(a[i]);
		t2.add(a[i],1);t3.add(a[i],a[i]);
		for(int j=a[i];j<=MAXV;j+=a[i]) t1.add(j,a[i]);
		printf("%lld%c",res," \n"[i==n]);
	}
    return 0;
}