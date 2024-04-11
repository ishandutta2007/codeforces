#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
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
const int N=1000005,mod=1000000007;
ll fac[N],ni[N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll fff(int n){
	return ksm(n,n-2);
}
ll c(int a,int b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
int main(){
	int n=read(),m=read(),ans=0;
	for(int i=fac[0]=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	ni[N-1]=ksm(fac[N-1],mod-2); for(int i=N-1;i;i--)ni[i-1]=ni[i]*i%mod;
	for(int i=0;i<=n-2&&i<m;i++){
		ans=(ans+c(m-1,i)*c(n-2,i)%mod*fac[i]%mod*ksm(m,n-i-2)%mod*((n-i-1)==1?1:(ksm(n,n-i-3)*(i+2)%mod)))%mod;
		//cout<<c(m-1,i)*c(n-2,i)%mod*fac[i]%mod*ksm(m,n-i-2)%mod*((n-i-1)==1?1:(fff(n-i-1)*(i+2)%mod))<<" "<<c(m-1,i)<<" "<<c(n-2,i)<<" "<<fac[i]<<" "<<ksm(m,n-i-2)<<" "<<((n-i-1)==1?1:(fff(n-i-1)*(i+2)))<<" "<<i+2<<endl;
	}
	cout<<ans<<endl;
}