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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
const int MAXM=35;
const int MAXP=1<<18;
const int MOD=998244353;
void add(int &x,int y){((x+=y)>=MOD)&&(x-=MOD);}
int n,m,mid,cnt=0,ans[MAXM+5];ll b[MAXM+5];
void ins(ll x){
	for(int i=m;~i;i--) if(x>>i&1){
		if(!b[i]){b[i]=x;cnt++;return;}
		else x^=b[i];
	}
}
int f1[MAXM/2+5][MAXP+5],f2[MAXP+5];
void dfs1(int x,ll num){
	if(x==mid-1){
		f1[__builtin_popcountll(num>>mid)][num&((1<<mid)-1)]++;
		return;
	} dfs1(x-1,num);if(b[x]) dfs1(x-1,num^b[x]);
}
void dfs2(int x,ll num){
	if(x==mid){f2[num]++;return;}
	dfs2(x+1,num);if(b[x]) dfs2(x+1,num^b[x]);
}
void FWTxor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++){
				int X=a[j+k],Y=a[(i>>1)+j+k];
				a[j+k]=1ll*(X+Y)*type%MOD;
				a[(i>>1)+j+k]=1ll*(X-Y+MOD)*type%MOD;
			}
}
int main(){
	scanf("%d%d",&n,&m);mid=m+1>>1;
	for(int i=1;i<=n;i++){ll x;scanf("%lld",&x);ins(x);}
	dfs1(m-1,0);dfs2(0,0);FWTxor(f2,1<<mid,1);
	for(int i=0;i<=m-mid;i++){
		FWTxor(f1[i],1<<mid,1);
		for(int j=0;j<(1<<mid);j++) f1[i][j]=1ll*f1[i][j]*f2[j]%MOD;
		FWTxor(f1[i],1<<mid,(MOD+1)/2);
		for(int j=0;j<(1<<mid);j++) add(ans[__builtin_popcount(j)+i],f1[i][j]);
	} int pw=1;for(int i=1;i<=n-cnt;i++) pw=2*pw%MOD;
//	for(int i=0;i<m;i++) printf("%lld\n",b[i]);
	for(int i=0;i<=m;i++) printf("%d ",1ll*ans[i]*pw%MOD);
	return 0;
}