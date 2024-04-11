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
const int MAXD=82;
const int INF=0x3f3f3f3f;
int n;ll fib[MAXD+5];
pii FG(int id,ll x){
//the minimum distance between x and 1 in graph id
//and the minimum distance between x and fib[id] in graph id
	if(x==fib[id]) return mp(id+1>>1,0);
	if(x==1) return mp(0,id+1>>1);
	if(x<=fib[id-1]){
		pii nt=FG(id-1,x);
		return mp(min(nt.fi,nt.se+2),min(nt.fi,nt.se)+1+FG(id-2,1).se);
	} else {
		pii nt=FG(id-2,x-fib[id-1]);
		return mp(nt.fi+1,nt.se);
	}
}
int query(ll a,ll b,int x,int len){
	if(x==1) return 1;
//	printf("%lld %lld %d %d\n",a,b,x,len);
	if(b<=fib[x-1]) return query(a,b,x-1,2);
	else if(a<=fib[x-1]){
		pii p1=FG(x-2,b-fib[x-1]),p2=FG(x-1,a);
		pii p3=FG(x,a),p4=FG(x,b);
		int res=p1.fi+1+min(p2.fi,p2.se);
		chkmin(res,p3.fi+p4.se+len);
		chkmin(res,p3.se+p4.fi+len);
		return res;
	} else return query(a-fib[x-1],b-fib[x-1],x-2,len+1);
}
int main(){
	fib[0]=1;fib[1]=2;
	for(int i=2;i<=MAXD;i++) fib[i]=fib[i-1]+fib[i-2];
	int qu;scanf("%d%d",&qu,&n);
	while(qu--){
		ll a,b;read(a);read(b);
		if(a>b) swap(a,b);
		if(a==b){print(0,'\n');continue;}
		int x=0;while(b>fib[x]) ++x;
		print(query(a,b,x,(x==n)?INF:2),'\n');
	} print_final();
	return 0;
}
/*
1 1000
89 55
*/