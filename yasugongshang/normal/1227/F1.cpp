#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=200005,mod=998244353;
ll fac[N],ni[N],fk[N],ans;
int h[N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int n=read(),k=read(),m=0;
	For(i,0,n-1)h[i]=read();
	For(i,0,n-1)m+=h[i]!=h[(i+1)%n];
	For(i,fk[0]=fac[0]=1,m){fk[i]=fk[i-1]*(k-2)%mod; fac[i]=fac[i-1]*i%mod;}
	ni[m]=ksm(fac[m],mod-2); Rep(i,m,1)ni[i-1]=ni[i]*i%mod;
	For(i,0,m)if((m-i)%2==0){
		int t=(m-i)/2;
		ans=(ans+fac[m]*ni[i]%mod*ni[t]%mod*ni[t]%mod*fk[i])%mod;
	}
	//cout<<ksm(k,m)<<" "<<ans<<endl;
	ans=(ksm(k,m)-ans+mod)%mod*(mod+1)/2%mod;
	For(i,1,n-m)ans=ans*k%mod;
	cout<<ans<<endl;
}