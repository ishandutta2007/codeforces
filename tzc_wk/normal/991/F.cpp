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
ll n,resa,resb,resc,resd,rese;int res=0;//a*b^c+d^e
unordered_map<ll,int> dp;
unordered_map<ll,pair<ll,pair<ll,ll> > > way;
int getdig(ll x){int d=0;while(x) d++,x/=10;return d;}
int main(){
	scanf("%lld",&n);
	if(n==10000000000ll) return puts("10^10"),0;
	resd=n;res=getdig(n);
	ll L=max(n-10000000,1ll),R=n;
	for(int i=2;i<=100000;i++){
		ll pw=1ll*i*i;int di=getdig(i);
		for(int e=2;pw<=1e10;e++,pw*=i){
			ll lft=(L-1)/pw*pw+pw,rit=R/pw*pw;
			int de=getdig(e);
			if(di+de+1+((lft==pw)?0:(getdig(lft/pw)+1))>=res) continue;
			for(ll j=lft;j<=rit;j+=pw){
				int num=di+de+1;//i^e
				if(j!=pw) num+=1+getdig(j/pw);
				if(j!=n) num+=getdig(n-j)+1;
				if(num<res){
					res=num;resa=j/pw;
					resb=i;resc=e;resd=n-j;
					rese=0;
				}
			}
		}
	}
	unordered_map<ll,pair<int,int> > pwc;
	for(int i=2;i<=999;i++){
		ll pw=i*i;
		for(int e=2;pw<=1e10;e++,pw*=i){
			int dig=getdig(i)+getdig(e)+1;
			if(!pwc.count(pw)||getdig(pwc[pw].fi)+getdig(pwc[pw].se)+1>dig)
				pwc[pw]=mp(i,e);
		}
	}
	for(int i=2;i<=99;i++){
		ll pw=i*i;
		for(int j=2;pw<=1e10;j++,pw*=i) if(n>=pw){
			if(pwc.count(n-pw)){
				pii p=pwc[n-pw];
				int dig=getdig(i)+1+getdig(j)+1+getdig(p.fi)+1+getdig(p.se);
				if(res>dig){
					res=dig;resa=1;resb=i;resc=j;
					resd=p.fi;rese=p.se;
				}
			}
			ll lft=n-pw;
			for(int k=2;k<=99;k++) if(lft%k==0&&pwc.count(lft/k)){
				pii p=pwc[lft/k];
				int dig=getdig(i)+1+getdig(j)+1+getdig(p.fi)+getdig(p.se)+1+getdig(k)+1;
				if(res>dig){
					res=dig;resa=k;resb=p.fi;
					resc=p.se;resd=i;rese=j;
				}
			}
		}
	}
	for(int i=2;i<=9;i++) for(int j=1;j<=9;j++)
		for(int k=2;k<=8;k++) for(int l=1;l<=9;l++){
			ll mul=1;
			for(int o=1;o<=j;o++) mul*=i;
			for(int o=1;o<=l;o++) mul*=k;
			if(mul==n&&res>7){
				printf("%d^%d*%d^%d\n",i,j,k,l);
				return 0;
			} if(n-mul<=9&&n-mul>0&&res>9){
				printf("%d^%d*%d^%d+%d\n",i,j,k,l,n-mul);
				return 0;
			}
		}
	if(!resa) printf("%lld",n);
	else{
		if(resa!=1) printf("%lld*",resa);
		printf("%lld^%lld",resb,resc);
		if(resd) printf("+%lld",resd);
		if(rese) printf("^%lld",rese);
	}
	return 0;
}
/*
16777227
4294967297
469762049
59823937
1953879661
10339840
7517728043
7781751697
1111000000
397575619
*/