#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10+'0');}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MOD=1e9+7;
void solve(){
	ll x;fastio::read(x);
	int d0=1,d1=1,d2=1,d3=1,d4=0,d5=0,d6=0,d7=0;
	int s0=1,s1=2,s2=3,s3=4,s4=4,s5=4,s6=4,s7=4;
	for(int i=1;i<=60;i++){
		register int nd=x>>i&1;
		nd?(d0=s1,d1=s3,d2=s5,d3=d4=d5=d6=d7=s7):(d0=s0,d1=s2,d2=s4,d3=s6,d4=d5=d6=d7=s7);
		#define mind(x,y) ((d##x-=s##y)<0)&&(d##x+=MOD)
		#define adds(x,y,z) ((s##x=s##y+d##z)>=MOD)&&(s##x-=MOD)
		!nd?(mind(4,0),mind(5,2),mind(6,4),mind(7,6)):(mind(4,1),mind(5,3),mind(6,5),mind(7,7));
		s0=d0;adds(1,0,1);adds(2,1,2);adds(3,2,3);adds(4,3,4);adds(5,4,5);adds(6,5,6);adds(7,6,7);
	} fastio::print(d0);fastio::putc('\n');
}
int main(){
	int T;fastio::read(T);
    while(T--) solve();fastio::print_final();
	return 0;
}