#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int M=200005,N=3005,mod=998244353;
int a[M],b[M],A,B;
ll dp[N][N],inv[N<<1];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int n=read(),m=read();
	For(i,1,n)a[i]=read();
	For(i,1,n){b[i]=read(); if(a[i])A+=b[i]; else B+=b[i];}
	For(i,-m,m)inv[i+m]=ksm(A+B+i,mod-2);
	dp[0][0]=1;
	For(i,0,m-1){
		For(j,0,i){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(B-(i-j))%mod*inv[2*j-i+m])%mod;
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(A+j)%mod*inv[2*j-i+m])%mod;
		}
	}
	ll ans1=0,ans0=0;
	For(i,0,m){ans1=(ans1+dp[m][i]*i%mod*ksm(A,mod-2))%mod; ans0=(ans0+dp[m][i]*(m-i)%mod*ksm(B,mod-2))%mod;}
	ans1++; ans0=1-ans0;
	ans1=(ans1+mod)%mod; ans0=(ans0+mod)%mod;
	For(i,1,n){
		if(a[i])writeln(ans1*b[i]%mod);
		else writeln(ans0*b[i]%mod);
	}
}
/*
dp[i][j]i
*/