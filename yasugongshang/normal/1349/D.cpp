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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=300005,mod=998244353;
PI f[N];
ll dp[N];
int a[N],n,sum;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
PI operator *(ll k,PI a){
	return mp(a.fi*k%mod,a.se*k%mod);
}
PI operator +(PI a,PI b){
	return mp(a.fi+b.fi,a.se+b.se);
}
void ycl(){
	f[sum-1]=mp(1,0);
	ll a=ksm(sum,mod-2),b=ksm(n-1,mod-2);
	Rep(i,sum-1,1){
		f[i-1]=-ksm(i,mod-2)*sum%mod*
		((sum-i)*a%mod*b%mod*f[i+1]+((sum-i)*a%mod*(1-b)%mod-1)*f[i]+mp(0,1));
	}
	PI c=b*f[1]+(n-2)*b%mod*f[0]+mp(0,1);
	ll X=(c.se-f[0].se)%mod*ksm((f[0].fi-c.fi)%mod,mod-2)%mod;
	For(i,0,sum)dp[i]=(f[i].fi*X+f[i].se)%mod;
	//For(i,0,sum)cout<<f[i].fi<<" "<<f[i].se<<" "<<(dp[i]+mod)%mod<<" "<<(c.fi*X+c.se)%mod<<endl;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n)sum+=(a[i]=read());
	ycl();
	ll ans=0;
	For(i,1,n)ans+=dp[a[i]];
	ans=((ans-(n-1)*dp[0])%mod+mod)%mod;
	cout<<ans*ksm(n,mod-2)%mod<<endl;
}