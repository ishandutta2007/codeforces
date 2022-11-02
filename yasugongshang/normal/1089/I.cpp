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
const int N=405;
ll dp[N][N],fac[N],ans[N],sum[N];
int main(){
	int T=read(),mod=read();
	int n=400;
	for(int i=fac[0]=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		sum[i]=fac[i];
		for(int j=1;j<i;j++)sum[i]=(sum[i]-sum[j]*fac[i-j])%mod;
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				dp[i][j]+=dp[i-k][j-1]*fac[k];
				if(!(k&15))dp[i][j]%=mod;
			}
			dp[i][j]%=mod;
		}
		ans[i]=fac[i];
		for(int j=4;j<i;j++)ans[i]=(ans[i]-ans[j]*dp[i][j])%mod;
		if(i>2)for(int j=1;j<i;j++)ans[i]=(ans[i]-2*sum[j]*fac[i-j])%mod;
	}
	while(T--){
		writeln((ans[read()]+mod)%mod);
	}
}