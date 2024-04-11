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
const int MAXN=500;
const int MAXM=2e5;
int m,k,a[MAXM+5],res[MAXN+5][MAXN+5],ord[MAXM+5];
void solve(){
	scanf("%d%d",&m,&k);int mx=0;
	for(int i=1;i<=k;i++) scanf("%d",&a[i]),chkmax(mx,a[i]);
	int sz;
	for(sz=1;;sz++) if(sz*sz-(sz>>1)*(sz>>1)>=m&&sz*(sz+1>>1)>=mx) break;
	for(int i=1;i<=sz;i++) for(int j=1;j<=sz;j++) res[i][j]=0;
	vector<pii> sp;vector<int> vec;
	for(int i=2;i<=sz;i+=2) for(int j=1;j<=sz;j+=2) sp.pb(mp(i,j));
	for(int i=1;i<=sz;i+=2) for(int j=1;j<=sz;j+=2) sp.pb(mp(i,j));
	for(int i=1;i<=sz;i+=2) for(int j=2;j<=sz;j+=2) sp.pb(mp(i,j));
	for(int i=1;i<=k;i++) ord[i]=i;
	sort(ord+1,ord+k+1,[&](int x,int y){return a[x]>a[y];});
	for(int i=1;i<=k;i++) for(int j=1;j<=a[ord[i]];j++) vec.pb(ord[i]);
	for(int i=0;i<vec.size();i++) res[sp[i].fi][sp[i].se]=vec[i];
	printf("%d\n",sz);
	for(int i=1;i<=sz;i++) for(int j=1;j<=sz;j++) printf("%d%c",res[i][j]," \n"[j==sz]);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}