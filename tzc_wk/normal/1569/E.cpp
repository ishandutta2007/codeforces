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
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int k,A,h,lim;
int st[33];
void gen(int msk,int *st){
	int cur=0;
	for(int j=2;j<=lim;j<<=1){
		for(int l=0;l<lim;l+=j){
			if(msk>>cur&1){
				int pos=-1;
				for(int p=l;p<l+(j>>1);p++) if(!st[p])
					pos=p;
				st[pos]=(lim*2/j)+1;
			} else {
				int pos=-1;
				for(int p=l+(j>>1);p<l+j;p++) if(!st[p])
					pos=p;
				st[pos]=(lim*2/j)+1;
			}
			cur++;
		}
	}
}
map<int,int> L[2];
map<int,int> R[2];
int main(){
	scanf("%d%d%d",&k,&A,&h);lim=(1<<(k-1));
	for(int i=0;i<(1<<lim-1);i++){
		memset(st,0,sizeof(st));gen(i,st);
		int sum0=0,sum1=0;
		for(int j=0;j<lim;j++){
			if(st[j]){
				sum0=(sum0+1ll*(j+1)*qpow(A,st[j]))%MOD;
				sum1=(sum1+1ll*(j+1)*qpow(A,st[j]))%MOD;
			} else {
				sum0=(sum0+1ll*(j+1)*qpow(A,1))%MOD;
				sum1=(sum1+1ll*(j+1)*qpow(A,2))%MOD;
			}
		} L[0][sum0]=i;L[1][sum1]=i;
//		printf("%d %d %d\n",i,sum0,sum1);
//		for(int j=0;j<lim;j++) printf("%d%c",st[j]," \n"[j==lim-1]);
	}
	for(int i=0;i<(1<<lim-1);i++){
		memset(st,0,sizeof(st));gen(i,st);
		int sum0=0,sum1=0;
		for(int j=0;j<lim;j++){
			if(st[j]){
				sum0=(sum0+1ll*(j+lim+1)*qpow(A,st[j]))%MOD;
				sum1=(sum1+1ll*(j+lim+1)*qpow(A,st[j]))%MOD;
			} else {
				sum0=(sum0+1ll*(j+lim+1)*qpow(A,1))%MOD;
				sum1=(sum1+1ll*(j+lim+1)*qpow(A,2))%MOD;
			}
		} R[0][sum0]=i;R[1][sum1]=i;
//		printf("%d %d %d\n",i,sum0,sum1);
	} for(pii p:L[0]){
		if(R[1].count((h-p.fi+MOD)%MOD)){
			fill0(st);
			int m1=p.se,m2=R[1][(h-p.fi+MOD)%MOD];
//			printf("%d %d\n",m1,m2);
			gen(m1,st+1);gen(m2,st+lim+1);
			for(int i=1;i<=lim;i++) if(!st[i]) st[i]=1;
			for(int i=1;i<=lim;i++) if(!st[i+lim]) st[i+lim]=2;
			for(int i=1;i<=(lim<<1);i++) printf("%d%c",st[i]," \n"[i==(lim<<1)]);
			return 0;
		}
	}
	for(pii p:L[1]){
		if(R[0].count((h-p.fi+MOD)%MOD)){
			fill0(st);
			int m1=p.se,m2=R[0][(h-p.fi+MOD)%MOD];
//			printf("%d %d\n",m1,m2);
			gen(m1,st+1);gen(m2,st+lim+1);
			for(int i=1;i<=lim;i++) if(!st[i]) st[i]=2;
			for(int i=1;i<=lim;i++) if(!st[i+lim]) st[i+lim]=1;
			for(int i=1;i<=(lim<<1);i++) printf("%d%c",st[i]," \n"[i==(lim<<1)]);
			return 0;
		}
	} puts("-1");
	return 0;
}