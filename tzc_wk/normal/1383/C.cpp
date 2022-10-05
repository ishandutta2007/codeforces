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
const int ALPHA=20;
const int MAXN=1e5;
const int MAXP=1048576;
int n,f[ALPHA+2],fr[ALPHA+2];
char s[MAXN+5],t[MAXN+5];
bool dp[MAXP+5];
void clear(){memset(f,-1,sizeof(f));memset(fr,0,sizeof(fr));memset(dp,0,sizeof(dp));}
int find(int x){return (!~f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);if(x^y) f[x]=y;}
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);clear();
	for(int i=1;i<=n;i++){
		int x=s[i]-'a',y=t[i]-'a';
		fr[x]|=(1<<y);merge(x,y);
	} int res=ALPHA<<1,mx=0;
	for(int i=0;i<ALPHA;i++) if(find(i)==i) res--;
	dp[0]=1;for(int i=0;i<MAXP;i++) if(dp[i]){
		chkmax(mx,__builtin_popcount(i));
		for(int j=0;j<ALPHA;j++) if(~i>>j&1){
			if((fr[j]&i)==0) dp[i|(1<<j)]=1;
		}
	} printf("%d\n",res-mx);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}