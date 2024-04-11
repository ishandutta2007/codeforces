#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=3605,mod=998244353;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll fac[N],ni[N];
int F[N][N/2],G[N][N/2],f[N],g[N];
inline void add(int &a,int b){
	a+=b; if(a>=mod)a-=mod;
}
ll p(int a,int b){
	return fac[a]*ni[a-b]%mod;
}
int main(){
	For(i,fac[0]=1,N-1)fac[i]=fac[i-1]*i%mod; ni[N-1]=ksm(fac[N-1],mod-2);
	Rep(i,N-1,1)ni[i-1]=ni[i]*i%mod;
	int h=read(),w=read(),n=read();
	For(i,1,h)f[i]=1; For(i,1,w)g[i]=1;
	For(i,1,n){
		f[read()]=0; g[read()]=0; f[read()]=0; g[read()]=0;
	}
	int hh=0,ww=0;
	For(i,1,h)hh+=f[i]; For(i,1,w)ww+=g[i];
	F[0][0]=F[1][0]=G[0][0]=G[1][0]=1;
	For(i,2,h){
		For(j,0,i/2){
			F[i][j]=F[i-1][j];
			if(f[i]&&f[i-1])add(F[i][j],F[i-2][j-1]);
		}
	}
	For(i,2,w){
		For(j,0,i/2){
			G[i][j]=G[i-1][j];
			if(g[i]&&g[i-1])add(G[i][j],G[i-2][j-1]);
		}
	}
	ll ans=0;
	For(i,0,h/2)for(int j=0;j+i*2<=hh&&j*2+i<=ww;j++){
		ans=(ans+p(hh-i*2,j)*p(ww-j*2,i)%mod*F[h][i]%mod*G[w][j])%mod;
	}
	cout<<ans<<endl;
}