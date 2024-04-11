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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int T=1.5e4;
const ll MOD=1e13;
const int SMOD=1e4;
const ll INF=1e18;
ll n;
ll smul(ll x,ll y){
	ll ret=0;
	for(;y;y>>=1,(x<<=1)%=MOD) if(y&1) (ret+=x)%=MOD;
	return ret;
}
struct mat{
	ll a[2][2];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat ret;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			ret.a[i][j]+=smul(a[i][k],rhs.a[k][j]);
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) ret.a[i][j]%=MOD;
		return ret;
	}
};
ll getf(ll ps){
	mat bs;bs.a[0][1]=bs.a[1][0]=bs.a[1][1]=1;
	mat rs;rs.a[0][0]=rs.a[1][1]=1;
	for(;ps;ps>>=1,bs=bs*bs) if(ps&1) rs=rs*bs;
	return rs.a[1][0];
}
vector<ll> can,tmp;
int main(){
	scanf("%lld",&n);
	for(ll i=1,p=0,q=1;i<=T;i++){
		if(q%SMOD==n%SMOD) can.pb(i);
		p=(p+q)%MOD;p^=q^=p^=q;
	} ll CT=T,CMOD=SMOD;
	while(CMOD^MOD){
		tmp.clear();CMOD*=10;
		for(ll x:can) for(int i=0;i<=9;i++)
			if(getf(CT*i+x)%CMOD==n%CMOD) tmp.pb(CT*i+x);
		swap(tmp,can);CT*=10;
	} ll res=INF;for(ll x:can) chkmin(res,x);
	printf("%lld\n",(res==INF)?-1:res);
	return 0;
}