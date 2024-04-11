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
const int MAXN=5e5;
const int LOG=50;
int qu,ncnt=1,fa[MAXN+5];
double dp[MAXN+5][LOG+2];
int main(){
	scanf("%d",&qu);
	for(int i=1;i<=LOG;i++) dp[1][i]=1;
	while(qu--){
		int opt,x;scanf("%d%d",&opt,&x);
		if(opt==1){
			vector<int> anc;ncnt++;fa[ncnt]=x;
			for(int i=1;i<=LOG;i++) dp[ncnt][i]=1;
			for(int i=0,cur=ncnt;i<=LOG&&cur;i++) anc.pb(cur),cur=fa[cur];
			for(int j=(int)(anc.size()-2);j;j--) dp[anc[j+1]][j+1]/=(dp[anc[j]][j]+1)/2.0;
			for(int j=0;j<(int)(anc.size()-1);j++) dp[anc[j+1]][j+1]*=(dp[anc[j]][j]+1)/2.0;
		} else {
			double ans=-1;
			for(int i=1;i<=LOG;i++) ans+=(dp[x][i]-dp[x][i-1])*i;
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}