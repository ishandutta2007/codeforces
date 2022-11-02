#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1000005,mod=1000000007;
int n,ans,a[N],p[N],f[N],dp[N];
ll sz[N],q[N];
int find(ll x){
	return upper_bound(&q[1],&q[n+1],x)-lower_bound(&q[1],&q[n+1],x);
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)p[i]=read();
	for(int i=n;i;i--){
		sz[i]+=a[i]; sz[p[i]]+=sz[i]; q[i]=sz[i];
	}
	sort(&q[1],&q[n+1]);
	for(int i=1;i<=n;i++)if(sz[1]%i==0){
		ll t=sz[1]/i; int dq=0;
		for(int j=1;j<=i;j++){
			dq+=find(t*j); if(dq<j)break;
		}
		if(dq==i)f[i]=1;
	}
	dp[1]=1;
	for(int i=1;i<=n;i++)if(f[i]){
		for(int j=i+i;j<=n;j+=i)dp[j]=(dp[j]+dp[i])%mod;
		ans=(ans+dp[i])%mod;
	}
	cout<<ans<<endl;
}