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
using namespace fastio;
const int MAXN=30;
const ll INF=3*3*7*257*65537*4294967297ll;
int n,qu,a[MAXN+3];
ll calc(int x,ll k){
	ll can=0,sum=0,res=0,cur_le=0;//cur_le means how many 1s can we obtain by dividing an interger <=2^x
	for(int i=0;i<n;i++) can+=1ll*(1<<i)*a[i];
	for(int i=0;i<=x;i++) cur_le+=1ll*((1<<i)-1)*a[i],sum+=a[i];
	if(can<k) return -1;
	k-=sum;int cur=x+1;if(k<0) return 0;
	for(;cur<n;cur++){
		int stp=1<<(cur-x),nd=min(k/stp,1ll*a[cur]);
		k-=1ll*stp*nd;res+=1ll*(stp-1)*nd;cur_le+=1ll*stp*nd*((1<<x)-1);
		if(nd<a[cur]) break;
	} if(!k) return res;ll ans=INF;
	if(cur==n) return res+k;
	for(;cur>x;){
		if(cur_le>=k) chkmin(ans,res+k);res++;cur--;int stp=1<<(cur-x);
		if(k>=stp) k-=stp,res+=stp-1,cur_le+=1ll*stp*((1<<x)-1);//divide them into 2^x
	} return min(ans,res+k);
}
int main(){
	read(n);read(qu);
	for(int i=0;i<n;i++) read(a[i]);
	while(qu--){
		int opt,x;ll y;read(opt);read(x);read(y);
		if(opt==1) a[x]=y;
		else print(calc(x,y),'\n');
	} print_final();
	return 0;
}