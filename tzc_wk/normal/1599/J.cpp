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
const int MAXN=1000;
const int HMOD=123457;
int n,a[MAXN+5],b[MAXN+5],m=0,vis[MAXN+5],res[MAXN+5];
vector<int> vec[2];
int hd[33][HMOD+2],nxt[4783000],key[4783000];
pii val[4783000];int item_n=0;
void ins(int id,int k,pii v){
	for(int e=hd[id][(k%HMOD+HMOD)%HMOD];e;e=nxt[e]) if(key[e]==k)
		return val[e]=v,void();
	key[++item_n]=k;val[item_n]=v;
	nxt[item_n]=hd[id][(k%HMOD+HMOD)%HMOD];
	hd[id][(k%HMOD+HMOD)%HMOD]=item_n;
}
pii query(int id,int k){
	for(int e=hd[id][(k%HMOD+HMOD)%HMOD];e;e=nxt[e]) if(key[e]==k)
		return val[e];
	return mp(-1,-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) b[++m]=a[i];
	if(m<n){
		int cur=0;puts("YES");
		for(int i=1;i<=m;i++) printf("%d ",cur),cur=b[i]-cur;
		printf("%d\n",cur);
		for(int i=1;i<=n-m-1;i++) printf("0 ");
		return 0;
	}
	if(n==2) return puts("NO"),0;
	if(n==3&&(a[1]+a[2]+a[3])&1) return puts("NO"),0;
	for(int i=1;i<=n;i++) vec[a[i]&1].pb(i);
	if(vec[0].size()){
		puts("YES");int x1,x2,x3;
		if(vec[1].size()>=2){
			x1=vec[1].back();vec[1].ppb();
			x2=vec[1].back();vec[1].ppb();
			x3=vec[0].back();vec[0].ppb();
		} else {
			x1=vec[0].back();vec[0].ppb();
			x2=vec[0].back();vec[0].ppb();
			x3=vec[0].back();vec[0].ppb();
		} int sum=a[x1]+a[x2]+a[x3]>>1;
		printf("%d %d %d ",sum-a[x1],sum-a[x2],sum-a[x3]);
		int cur=sum-a[x3];
		for(int id:vec[0]) cur=a[id]-cur,printf("%d ",cur);
		for(int id:vec[1]) cur=a[id]-cur,printf("%d ",cur);
		return 0;
	} int A=-1,B=-1;
	int lim=min(n,28),mid=(lim+1>>1);
	static int suml[16400],sumr[16400];
	for(int j=1;j<(1<<mid);j++) suml[j]=suml[j&(j-1)]+a[32-__builtin_clz(j&(-j))];
	for(int j=1;j<(1<<lim-mid);j++) sumr[j]=sumr[j&(j-1)]+a[32-__builtin_clz(j&(-j))+mid];
	for(int j=0;j<(1<<mid);j++){
		int rst=((1<<mid)-1)^j;
		for(int S=rst;;--S&=rst){
			int dif=__builtin_popcount(j)-__builtin_popcount(S);
//			printf("%d %d %d\n",j,S,suml[j]-suml[S]);
			ins(dif+16,suml[j]-suml[S],mp(j,S));
			if(!S) break;
		}
	}
	for(int j=0;j<(1<<lim-mid);j++){
		int rst=((1<<lim-mid)-1)^j;
		for(int S=rst;;--S&=rst){
//			printf("%d %d %d\n",j,S,sumr[S]-sumr[j]);
			int dif=__builtin_popcount(S)-__builtin_popcount(j);
			pii p=query(dif+16,sumr[S]-sumr[j]);
			if(!~p.fi){if(!S) break;continue;}
			int mA=p.fi|(j<<mid),mB=p.se|(S<<mid);
			if(mA||mB){A=mA;B=mB;break;}
			if(!S) break;
		} if(~A) break;
	}
	if(!~A) return puts("NO"),0;
//	printf("%d %d\n",A,B);
//	int sumA=0,sumB=0;
//	for(int i=0;i<28;i++) if(A>>i&1) sumA+=a[i+1];
//	for(int i=0;i<28;i++) if(B>>i&1) sumB+=a[i+1];
//	assert(sumA==sumB);
	for(int i=0;i<28;i++) if(A>>i&1) vis[i+1]=1;
	for(int i=0;i<28;i++) if(B>>i&1) vis[i+1]=1;
	int len=__builtin_popcount(A)<<1,cur=0;
	assert(__builtin_popcount(A)==__builtin_popcount(B));
	for(int i=1;i<=len;i++){
		if(i&1) res[i]=a[32-__builtin_clz(A&(-A))]-cur,A&=(A-1),cur=res[i];
		else res[i]=a[32-__builtin_clz(B&(-B))]-cur,B&=(B-1),cur=res[i];
	}
	for(int i=1;i<=n;i++) if(!vis[i]) cur=a[i]-cur,res[++len]=cur;
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
/*
5
1 11 111 1111 1112

5
1 3 7 9 13

10
65 653 741 367 83 123 697 709 75 225
*/