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
const int MAXN=200;
const int MAXM=300;
const int MOD=1e4+7;
int n,m,k;char s[MAXN+5];
struct mat{
	ll a[MAXM+5][MAXM+5];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=1;i<=k;i++) for(int l=1;l<=i;l++) for(int j=1;j<=l;j++)
			res.a[i][j]+=a[i][l]*rhs.a[l][j];
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) res.a[i][j]%=MOD;
		return res;
	}
};
int dp[MAXN+5][MAXN+5][MAXN+5];
int dfs(int x,int l,int r){
	if(x<0) return 0;
	if(~dp[x][l][r]) return dp[x][l][r];
	if(l==1&&r==m) return dp[x][l][r]=(!x);
	dp[x][l][r]=0;
	if(l!=1&&s[l-1]!=s[r]) dp[x][l][r]=(dp[x][l][r]+dfs(x-1,l-1,r))%MOD;
	if(r!=m&&s[l]!=s[r+1]) dp[x][l][r]=(dp[x][l][r]+dfs(x-1,l,r+1))%MOD;
	if(l!=1&&r!=m&&s[l-1]==s[r+1]) dp[x][l][r]=(dp[x][l][r]+dfs(x,l-1,r+1))%MOD;
	return dp[x][l][r];
}
int main(){
	scanf("%s%d",s+1,&n);m=strlen(s+1);k=m+((m+1)>>1);
	memset(dp,-1,sizeof(dp));mat st,trs,res;
	for(int i=0;i<m;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			cnt=(cnt+dfs(i,j,j))%MOD;
			if((j^m)&&!(s[j]^s[j+1])) cnt=(cnt+dfs(i,j,j+1))%MOD;
		}
//		printf("%d %d\n",i,cnt);
		if(i) trs.a[k-((m-i+1)>>1)][i]=cnt;
		else st.a[m][1]=cnt;
	}
	for(int i=2;i<m;i++) trs.a[i][i-1]=1;
	if(m>1) st.a[1][1]=1;
	for(int i=m;i<k;i++) trs.a[i+1][i]=1;
	for(int i=1;i<m;i++) trs.a[i][i]=24;
	for(int i=m;i<k;i++) trs.a[i][i]=25;
	trs.a[k][k]=26;
	for(int i=1;i<=k;i++) res.a[i][i]=1;
//	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) printf("%d%c",trs.a[i][j],(j==k)?'\n':' ');
	int stp=(n+m+1)>>1;
	for(;stp;stp>>=1,trs=trs*trs) if(stp&1) res=res*trs;
//	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) printf("%d%c",res.a[i][j],(j==k)?'\n':' ');
	int sum=0;for(int i=1;i<=k;i++) sum=(sum+st.a[i][1]*res.a[k][i])%MOD;
	if(!((n+m)&1)) return printf("%d\n",sum),0;
	int ans=sum;
	memset(res.a,0,sizeof(res.a));memset(trs.a,0,sizeof(trs.a));
	memset(st.a,0,sizeof(st.a));
	for(int i=0;i<m;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			if((j^m)&&!(s[j]^s[j+1])) cnt=(cnt+dfs(i,j,j+1))%MOD;
		}
		if(i) trs.a[k-((m-i+1)>>1)][i]=cnt;
		else st.a[m][1]=cnt;
	}
	for(int i=2;i<m;i++) trs.a[i][i-1]=1;
	if(m>1) st.a[1][1]=1;
	for(int i=m;i<k;i++) trs.a[i+1][i]=1;
	for(int i=1;i<m;i++) trs.a[i][i]=24;
	for(int i=m;i<k;i++) trs.a[i][i]=25;
	for(int i=1;i<=k;i++) res.a[i][i]=1;
	stp=(n+m+1)>>1;
	for(;stp;stp>>=1,trs=trs*trs) if(stp&1) res=res*trs;
	sum=0;for(int i=1;i<=k;i++) sum=(sum+st.a[i][1]*res.a[k][i])%MOD;
	printf("%d\n",(ans-sum+MOD)%MOD);
	return 0;
}