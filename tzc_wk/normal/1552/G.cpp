//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=40;
int n,k,c[MAXN+5];
ll tot[MAXN+5];int c_new[MAXN+5];
ll pre[MAXN+5][MAXN+5],msk[MAXN+5];
bool dfs(int x,ll S){
	if(x==k){
		ll ought_S=((1ll<<n)-1)&(~((1ll<<n-__builtin_popcountll(S))-1));
		ll dif=ought_S^S;return (dif&msk[x])==dif;
	} int mn=__builtin_popcountll(S&msk[x]);S|=msk[x];
	for(int i=mn;i<=mn+c_new[x];i++)
		if(!dfs(x+1,S&pre[x][i])) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);if(n==1) return puts("ACCEPTED"),0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);pre[i][c[i]]=(1ll<<n)-1;
		for(int j=1,x;j<=c[i];j++){
			scanf("%d",&x);msk[i]|=(1ll<<x-1);
			pre[i][c[i]-j]=~msk[i]&((1ll<<n)-1);
		} c_new[i]=__builtin_popcountll(msk[i]&(~tot[i]));
		tot[i+1]=msk[i]|tot[i];
	} if(tot[k+1]!=(1ll<<n)-1) return puts("REJECTED"),0;
	printf("%s\n",dfs(1,0)?"ACCEPTED":"REJECTED");
	return 0;
}