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
#define bitcnt __builtin_popcount
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
const int MAXP=1<<18;
const int MAXN=18;
int n;ll dp[MAXP+5][MAXN+5],g[MAXN+5][MAXP+5];
char s[MAXN+5][MAXN+5];
void FWTor(ll *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++)
				a[(i>>1)+j+k]+=a[j+k]*type;
}
void FWTand(ll *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++)
				a[j+k]+=a[(i>>1)+j+k]*type;
}
map<vector<int>,ll> ret;
vector<int> cur;
ll mul[MAXN+5][MAXP+5],ans[MAXP+5];
void dfs(int x,int lst){
	if(x==n+1){
		ll sum=0;
		for(int i=0;i<(1<<n);i++){
			int dig=bitcnt(((1<<n)-1)^i)&1;
			if(dig) sum-=mul[cur.size()][i];
			else sum+=mul[cur.size()][i];
		} ret[cur]=sum;
//		for(int x:cur) printf("%d ",x);printf("%lld\n",sum);
		return;
	}
	for(int i=lst;i<=n-x+1;i++){
		cur.pb(i);
		for(int j=0;j<(1<<n);j++) mul[cur.size()][j]=mul[cur.size()-1][j]*g[i][j];
		dfs(x+i,i);cur.pop_back();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) dp[1<<i-1][i]=1;
	for(int i=1;i<(1<<n);i++) for(int j=1;j<=n;j++) if(i>>(j-1)&1){
		for(int k=1;k<=n;k++) if((i>>(k-1)&1)&&j!=k&&s[k][j]=='1'){
			dp[i][j]+=dp[i^(1<<j-1)][k];
		} g[bitcnt(i)][i]+=dp[i][j];
	}
//	for(int i=1;i<(1<<n);i++) printf("%lld\n",g[bitcnt(i)][i]);
	for(int i=1;i<=n;i++) FWTor(g[i],1<<n,1);
	for(int i=0;i<(1<<n);i++) mul[0][i]=1;dfs(1,1);
	for(int i=0;i<(1<<n-1);i++){
		vector<int> v;int pre=-1;
		for(int j=0;j<n-1;j++) if(~i>>j&1){
			v.pb(j-pre);pre=j;
		} v.pb(n-1-pre);sort(v.begin(),v.end());
//		for(int x:v) printf("%d ",x);printf("\n");
		ans[i]=ret[v];
	} FWTand(ans,1<<n-1,-1);
	for(int i=0;i<(1<<n-1);i++) printf("%lld ",ans[i]);
	return 0;
}