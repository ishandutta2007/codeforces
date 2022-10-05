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
int _1,_2,_3;
pair<ll,int> a[4];int flg=0;
void getid(){sort(a+1,a+4);_1=a[1].se,_2=a[2].se,_3=a[3].se;}
void prt(){
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) if(a[j].se==i)
		printf("%d%c",a[j].fi," \n"[i==3]);
	printf("%d %d %d\n",_1,_2,_3);
}
void oper(ll x){
	if(!x) return;
	printf("%lld\n",x);fflush(stdout);
	int p;scanf("%d",&p);
	if(!p) exit(0);
	if(p==_1) a[1].fi+=x,flg=1;
	if(p==_2) a[2].fi+=x,flg=2;
	if(p==_3) a[3].fi+=x,flg=3;
//	prt();
	getid();
}
void work(int stage){
	if(stage==2){
		oper(abs(a[3].fi-a[2].fi));
	}  else {
		oper(abs(a[3].fi-a[2].fi));
		oper(5*abs(a[2].fi-a[1].fi));
		work(2);
	}
}
int main(){
	scanf("%lld%lld%lld",&a[1].fi,&a[2].fi,&a[3].fi);puts("First");
	a[1].se=1;a[2].se=2;a[3].se=3;getid();
	if(2ll*a[2].fi==a[1].fi+a[3].fi) work(1);
	else{
		ll d1=abs(a[2].fi-a[1].fi),d2=abs(a[3].fi-a[2].fi);
		while(d2*2<d1||d1<d2){
			oper(d1+d2);d1=abs(a[2].fi-a[1].fi);
			d2=abs(a[3].fi-a[2].fi);
		} //puts("-1");
		oper(abs(d1-d2));
		if(flg==1) work(1);
		else if(flg==2){
			d1=abs(a[2].fi-a[1].fi),d2=abs(a[3].fi-a[2].fi);
			oper(abs(d1-d2));
			if(flg==1) work(1);
			else work(2);
		} else work(2);
	}
	return 0;
}