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
const int MAXN=100;
int n,k,x[MAXN+5],y[MAXN+5],mark[MAXN*2+5];
void solve(){
	scanf("%d%d",&n,&k);memset(mark,0,sizeof(mark));
	for(int i=1;i<=k;i++) scanf("%d%d",&x[i],&y[i]),mark[x[i]]=mark[y[i]]=1;
	vector<int> vec;int tmp=k;
	for(int i=1;i<=n<<1;i++) if(!mark[i]) vec.pb(i);
	for(int i=0;i<n-k;i++) x[++tmp]=vec[i],y[tmp]=vec[n-k+i];
	for(int i=1;i<=n;i++) if(x[i]>y[i]) swap(x[i],y[i]);
	int res=0;for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j]) res++;
	} printf("%d\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
    return 0;
}