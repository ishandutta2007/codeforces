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
const int MAXK=8;
const int MAXP=25;
const int MAX_SIZ=70;
const int LOG_N=28;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int x,k,n,p,c[MAXK+2];pii t[MAXP+2];
int st[MAX_SIZ+5],st_n=0,id[1<<MAXK];
struct mat{
	int n,m;ll a[MAX_SIZ+5][MAX_SIZ+5];
	mat(){}
	mat(int _n,int _m){
		n=_n;m=_m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			a[i][j]=INF;
	}
	mat operator *(const mat &rhs){
		assert(m==rhs.n);mat res(n,rhs.m);
		for(int i=1;i<=n;i++) for(int j=1;j<=rhs.m;j++)
			for(int l=1;l<=m;l++) chkmin(res.a[i][j],a[i][l]+rhs.a[l][j]);
		return res;
	}
};
mat pw[LOG_N+2];
int main(){
	scanf("%d%d%d%d",&x,&k,&n,&p);
	for(int i=1;i<=k;i++) scanf("%d",&c[i]);
	for(int i=1;i<=p;i++) scanf("%d%d",&t[i].fi,&t[i].se);
	sort(t+1,t+p+1);
	for(int i=0;i<(1<<k);i++) if(__builtin_popcount(i)==x){
		st[++st_n]=i;id[i]=st_n;//printf("%d\n",i);
	} mat trs(st_n,st_n);
	for(int i=1;i<=st_n;i++){
		if(st[i]>>(k-1)&1){
			trs.a[id[((st[i]^(1<<(k-1)))<<1)|1]][i]=c[k];
		} else {
			for(int j=0;j<k;j++) if(st[i]>>j&1)
				trs.a[id[((st[i]^(1<<j))<<1)|1]][i]=c[j+1];
			trs.a[id[st[i]<<1]][i]=0;
		}
	}
//	for(int i=1;i<=st_n;i++) for(int j=1;j<=st_n;j++)
//		printf("%lld%c",trs.a[i][j],(j==st_n)?'\n':' ');
	pw[0]=trs;
	for(int i=1;i<=LOG_N;i++) pw[i]=pw[i-1]*pw[i-1];
	int pre=x,init_msk=0;mat cur(st_n,1);
	for(int i=0;i<x;i++) init_msk|=1<<i;
	cur.a[id[init_msk]][1]=0;
	for(int i=1;i<=p;i++){
		int dif=t[i].fi-pre;
		for(int j=LOG_N;~j;j--) if(dif>>j&1) cur=pw[j]*cur;
		for(int j=1;j<=st_n;j++) if(st[j]&1) cur.a[j][1]+=t[i].se;
		pre=t[i].fi;
	}
	int dif=n-pre;
	for(int j=LOG_N;~j;j--) if(dif>>j&1) cur=pw[j]*cur;
	printf("%lld\n",cur.a[id[init_msk]][1]);
//	for(int i=1;i<=st_n;i++) printf("%d %lld\n",st[i],cur.a[i][1]);
	return 0;
}
/*
2 8 85 25
492266845 33510072 886523743 473694882 423098690 347309510 536406077 916069301
68 -670378539
8 141902011
43 -84030444
19 -519169748
56 -187064805
14 -237674403
31 -544566859
76 58127796
64 -222971417
83 -712619543
20 -767112722
59 -831456183
13 489832592
15 -789976137
39 318003101
66 491222453
70 23439534
58 -185371556
69 -21442899
61 -735529104
60 77989991
63 -11663315
44 -295106551
54 -41933766
48 662973000

2 3 3 0
1 2 3
*/