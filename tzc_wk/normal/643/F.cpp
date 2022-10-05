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
typedef unsigned int u32;
const int MAXN=130;
u32 gcd(int x,int y){return (!y)?x:gcd(y,x%y);}
int n,p,q;u32 c[MAXN+5];
u32 calc(int x){
	vector<u32> a,b;
	for(int i=1;i<=x;i++) a.pb(n-i+1),b.pb(i);
	for(int i=0;i<a.size();i++) for(int j=0;j<b.size();j++){
		u32 d=gcd(a[i],b[j]);a[i]/=d;b[j]/=d;
	} u32 prod=1;
	for(int i=0;i<a.size();i++) prod*=a[i];
	return prod;
}
int main(){
	scanf("%d%d%d",&n,&p,&q);p=min(n-1,p);
	for(int i=0;i<=p;i++) c[i]=calc(i);u32 ans=0;
	for(int i=1;i<=q;i++){
		u32 prod=1,sum=0;
		for(int j=0;j<=p;j++){
			sum+=prod*c[j];
			prod*=i;
		} ans^=i*sum;
	} printf("%u\n",ans);
	return 0;
}