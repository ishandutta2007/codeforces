#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int mod=998244353,N=2000005;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll n,m,fac[N<<1],ni[N<<1];
ll c(int a,int b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	
	n=read(); m=read();
	For(i,fac[0]=1,n+m)fac[i]=fac[i-1]*i%mod;
	ni[n+m]=ksm(fac[n+m],mod-2);
	Rep(i,n+m,1)ni[i-1]=ni[i]*i%mod;
	ll ans=0;
	For(i,1,n){
	//	cerr<<c(n,i)*(i%2?1:mod-1)%mod<<" "<<fac[i]%mod*fac[m]%mod*ni[m+i]%mod<<" "<<ksm(mod+1-fac[i]%mod*fac[m]%mod*ni[m+i]%mod,mod-2)<<endl;
		ans=(ans+c(n,i)*(i%2?1:mod-1)%mod*(i+m)%mod*(fac[i-1]*ni[i]%mod))%mod;
	}
	//cerr<<ans<<endl;
	cout<<(n*ksm(m+1,mod-2)+1)%mod*ans%mod*1%mod<<endl;
}