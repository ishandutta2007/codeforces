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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=500;
const int MOD=998244353;
int n,a[MAXN*2+5][MAXN+5],cnt[MAXN+5],book[MAXN*2+5];
void solve(){
	scanf("%d",&n);memset(book,0,sizeof(book));int ans=1;
	for(int i=1;i<=n<<1;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		int id=0;
		for(int j=1;j<=n;j++){
			memset(cnt,0,sizeof(cnt));
			for(int k=1;k<=n<<1;k++) if(!book[k]) cnt[a[k][j]]++;
			for(int k=1;k<=n<<1;k++) if(!book[k]&&cnt[a[k][j]]==1){
				book[k]=1;id=k;break;
			} if(id) break;
		} if(!id){
			(ans<<=1)%=MOD;
			do {++id;} while(book[id]);
		} book[id]=1;
		for(int j=1;j<=n<<1;j++) if(!book[j]){
			bool flg=0;
			for(int k=1;k<=n;k++) flg|=(a[j][k]==a[id][k]);
			if(flg) book[j]=2;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n<<1;i++) (book[i]==1&&printf("%d ",i));printf("\n");
}
int main(){int qu;scanf("%d",&qu);while(qu--) solve();return 0;}