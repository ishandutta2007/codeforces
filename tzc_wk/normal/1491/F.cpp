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
const int MAXN=2000;
int n,book[MAXN+5];
void solve(){
	memset(book,0,sizeof(book));
	scanf("%d",&n);vector<int> res;int fst=-1;
	for(int i=2;i<=n;i++){
		printf("? 1 %d\n",i-1);printf("%d\n",i);
		for(int j=1;j<=i-1;j++) printf("%d%c",j," \n"[j==i-1]);
		fflush(stdout);int v;scanf("%d",&v);
		if(v){
			for(int j=i+1;j<=n;j++){
				printf("? 1 1\n%d\n%d\n",i,j);fflush(stdout);
				int x;scanf("%d",&x);if(x) res.pb(j);
			} fst=i;res.pb(i);
			break;
		}
	} int l=1,r=fst-1,p=0;
	while(l<=r){
		int mid=l+r>>1;
		printf("? %d 1\n",mid);
		for(int i=1;i<=mid;i++) printf("%d%c",i," \n"[i==mid]);
		printf("%d\n",fst);fflush(stdout);
		int v;scanf("%d",&v);
		if(v) p=mid,r=mid-1;else l=mid+1;
	} res.pb(p);for(int x:res) book[x]=1;
	vector<int> nt;for(int i=1;i<=n;i++) if(!book[i]) nt.pb(i);
	printf("! %d",nt.size());for(int x:nt) printf(" %d",x);
	printf("\n");fflush(stdout);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}