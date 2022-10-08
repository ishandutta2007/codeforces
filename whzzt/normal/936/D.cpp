#include<bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc()getchar()
	#else
		#define gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N=2000005;

int n,m,e,m1,m2,t;
pi st[N];

int pos[N],cht[N][2],dp[N][2];
bool ob[N][2];

void output_move(){
	vector<int>move;
	int p=m,q=0;
	while(p!=1||q!=0){
		if(cht[p][q]){
			q^=1;
			if(p!=m)move.pb(pos[p]);
		}else p--;
	}
	reverse(ALL(move));
	print(move.size());putc('\n');
	for(int v:move)print(v),putc(' ');
	putc('\n');
}
void output_shot(){
	vector<pi>shot;
	int p=m,q=0;
	while(p!=1||q!=0){
		if(ob[p][q])shot.pb(pi(pos[p]-dp[p][q],q+1));
		if(cht[p][q])q^=1;else p--;
	}
	reverse(ALL(shot));
	print(shot.size());putc('\n');
	for(auto i:shot)print(i.fi),putc(' '),print(i.se),putc('\n');
}

int main(){
	gi(n);gi(m1);gi(m2);gi(t);int x;
	fo(i,1,m1)gi(x),st[++e]=pi(x,1),st[++e]=pi(x+1,0);
	fo(i,1,m2)gi(x),st[++e]=pi(x,2),st[++e]=pi(x+1,0);
	st[++e]=pi(n+1,0);st[++e]=pi(0,0);sort(st+1,st+e+1);
	fo(i,(m=1)+1,e)if(st[i].fi!=st[m].fi)st[++m]=st[i];else st[m].se|=st[i].se;
	fo(i,1,m){
		pos[i]=st[i].fi;
		if(st[i].se&1)ob[i][0]=true;
		if(st[i].se&2)ob[i][1]=true;
	}
	memset(dp,-1,sizeof(dp));
	dp[1][0]=0;dp[1][1]=0;cht[1][1]=1;
	fo(i,2,m){
		fo(j,0,1)if(~dp[i-1][j]){
			dp[i][j]=max(dp[i-1][j]+(pos[i]-pos[i-1]-1)-(int)ob[i][j]*t,-1);
			if(~dp[i][j])cht[i][j]=0;
		}
		if(!~dp[i][0]&&!~dp[i][1])puts("No"),exit(0);
		fo(j,0,1)if(!ob[i][j])if(min(dp[i][j^1],t)>dp[i][j])
			dp[i][j]=min(dp[i][j^1],t-1),cht[i][j]=1;
		fo(j,0,1)if(~dp[i][j])dp[i][j]++;
	}
	ps("Yes");putc('\n');
	output_move();
	output_shot();
	io::flush();
	return 0;
}