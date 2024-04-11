#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
const int N=200005,mod=998244353,inv=(mod+1)/2;
int n,m,A,f[N],b[N];
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	n=read(); m=read(); A=read();
	for(int i=1;i<=m;i++)b[i]=read();
	ll t=1,ans=1;
	for(int i=0;i<m;i++){
		ll t=ksm(A,b[i+1]-b[i]);
		ans=(ans*t%mod*(t+1))%mod;
	}
	cout<<ans*ksm(inv,m)%mod*ksm(A,n-b[m]-b[m])%mod<<endl;
}