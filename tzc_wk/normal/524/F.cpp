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
const int MAXN=1e6;
const int LOG_N=20;
const int INF=0x3f3f3f3f;
const int BS=191;
const int MOD=998244853;
int n,pre[MAXN*2+5];char s[MAXN*2+5];
int hs[MAXN*2+5],pw[MAXN*2+5];
int gethash(int l,int r){return (hs[r]-1ll*pw[r-l+1]*hs[l-1]%MOD+MOD)%MOD;}
int getlcp(int x,int y){
	int l=1,r=n,p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(gethash(x,x+mid-1)==gethash(y,y+mid-1)) p=mid,l=mid+1;
		else r=mid-1;
	} return p;
}
bool cmp(int x,int y){//whether x is better than y
	int len=getlcp(x+1,y+1);//printf("len=%d %d %d\n",len,x,y);
	return s[x+1+len]<s[y+1+len];
}
int st[LOG_N+2][MAXN+5];
int query_st(int l,int r){
	if(l>r) return INF;
	int k=31-__builtin_clz(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) s[i+n]=s[i];
	for(int i=(pw[0]=1);i<=MAXN*2;i++) pw[i]=1ll*pw[i-1]*BS%MOD;
	for(int i=1;i<=n*2;i++) hs[i]=(1ll*hs[i-1]*BS+s[i])%MOD;
	int sum=0,mn=0;//printf("%d\n",gethash(6,6));
	for(int i=1;i<=n;i++){
		if(s[i]=='(') ++sum;else --sum;
		chkmin(mn,sum);pre[i]=sum;st[0][i]=pre[i];
	}
	for(int i=1;i<=LOG_N;i++) for(int j=0;j+(1<<i)-1<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	int mnp=0;
	for(int i=1;i<=n;i++){
		if(sum>0&&query_st(i+1,n)-pre[i]<0) continue;
		if(sum>0&&query_st(0,i)+pre[n]-pre[i]<0) continue;
		if(sum<=0&&query_st(i+1,n)-pre[i]-sum<0) continue;
		if(sum<=0&&query_st(0,i)-sum+pre[n]-pre[i]<0) continue;
//		printf("%d\n",i);
		if(!mnp) mnp=i;
		else if(cmp(i,mnp)) mnp=i;
	} //printf("%d\n",mnp);
	if(sum<0) for(int i=1;i<=-sum;i++) putchar('(');
	for(int i=mnp+1;i<=mnp+n;i++) putchar(s[i]);
	if(sum>0) for(int i=1;i<=sum;i++) putchar(')');
	return 0;
}
/*
)())))(((())))())))))))()())(())))))))())))(((())))())()()))(())())((()())(((((()()()())()()()))((()
*/