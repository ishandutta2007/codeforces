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
const int MAXN=1e6;
const int MOD=1e9+7;
char s[MAXN+5];pii seg[MAXN+5];int pcnt=0;
int n,nxt[MAXN+5][2],dp[MAXN+5][2];
void add(int &x,int y){((x+=y)>=MOD)&&(x-=MOD);}
int main(){
	scanf("%s",s+1);n=strlen(s+1);int fst=0,lst=0;
	for(int i=1;i<=n;i++) if(s[i]^48){fst=i;break;}
	for(int i=n;i;i--) if(s[i]^48){lst=i;break;}
	if(!fst) return printf("%d\n",n),0;
	for(int l=1,r;l<=n;l=r+1){
		r=l;if(s[l]^48) continue;
		while(s[r]^49&&r<=n) r++;seg[++pcnt]=mp(r-1,r-l);
	} int pre=n+1;
	for(int i=n;i;i--){nxt[i][1]=pre;if(s[i]^48) pre=i;}
	pre=n+1;
	for(int i=n;i;i--){
		if(s[i]^49) pre=i;
		else nxt[i][0]=pre;
	}
	for(int i=1;i<=n;i++) if((s[i]^49)&&(s[i+1]^49))
		nxt[i][0]=i+1;
	stack<pii> stk;
	for(int i=pcnt;i;i--){
		while(!stk.empty()&&stk.top().se<=seg[i].se) stk.pop();
		if(!stk.empty()) nxt[seg[i].fi][0]=stk.top().fi-stk.top().se+1+seg[i].se;
		else nxt[seg[i].fi][0]=n+1;stk.push(seg[i]);
	}
//	for(int i=1;i<=n;i++) printf("%d %d\n",nxt[i][0],nxt[i][1]);
	dp[fst][1]=1;int ans=0;
	for(int i=fst;i<=n;i++) for(int j=0;j<2;j++){
		for(int k=0;k<2;k++) if(nxt[i][k]<=n) add(dp[nxt[i][k]][k],dp[i][j]);
		if(j==1) add(ans,dp[i][j]);
	} printf("%d\n",1ll*ans*fst%MOD*(n-lst+1)%MOD);
	return 0;
}