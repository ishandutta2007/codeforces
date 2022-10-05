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
const int MAXN=1e5;
int n,pr[MAXN/5+5],prcnt=0;
bool vis[MAXN+5],is[MAXN+5],has[MAXN+5];
vector<int> fac[MAXN+5];
int cnt[MAXN+5];
void sieve(){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
	for(int i=1;i<=n;i++) cnt[i]=n/i;
	for(int i=1;i<=prcnt;i++) for(ll j=pr[i];j<=n;j*=pr[i]) is[j]=1;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) fac[j].pb(i);
}
void del(int x){for(int y:fac[x]) cnt[y]--;has[x]=1;}
void del_mul(int x){for(int i=x;i<=n;i+=x) if(!has[i]) del(i);}
int qr1(int x){printf("A %d\n",x);fflush(stdout);int res;scanf("%d",&res);return res;}
int qr2(int x){printf("B %d\n",x);fflush(stdout);int res;scanf("%d",&res);return res;}
int main(){
	scanf("%d",&n);sieve();
	int cur=1,mn=prcnt,cc=0,fst_blk=0;
	for(int i=1;i<=prcnt;i++){
		int t=qr2(pr[i]);
		if(t!=cnt[pr[i]]){
			if(cur==1) mn=i;del_mul(pr[i]);
			cur*=pr[i];
			for(ll x=1ll*pr[i]*pr[i];x<=n;x*=pr[i]){
				int num=qr1(x);//printf("%d %d\n",x,cnt[x]);
				if(num==cnt[x]) break;cur*=pr[i];
			}
		} else del_mul(pr[i]);
		++cc;
		if(cc==100&&!fst_blk){
			cc=0;int x=qr1(1);
			if(x!=cnt[1]) fst_blk=i;
		}
	} if(!fst_blk){int x=qr1(1);if(x!=cnt[1]) fst_blk=prcnt;}
	for(int j=(fst_blk-1)/100*100+1;j<=min(fst_blk,mn);j++){
		int x=qr1(pr[j]);
		if(x!=cnt[pr[j]]){
			cur*=pr[j];
			for(ll k=1ll*pr[j]*pr[j];k<=n;k*=pr[j]){
				int num=qr1(k);//printf("%d %d\n",x,cnt[x]);
				if(num==cnt[k]) break;cur*=pr[j];
			} break;
		}
	}
	printf("C %d\n",cur);fflush(stdout);
	return 0;
}