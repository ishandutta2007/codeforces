#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<ll,ll>
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
const int N=200005,n=200000;
int tot,f[N],dp[N],q[N],zs[N];
bitset<N> s,S[100];
int main(){
	int T=read(),F=read(),ans=0;
	for(int i=2;i<=n;i++)q[i]=i;
	for(int i=2;i<=n;i++)if(!f[i]){
		for(int j=i;j<=n;j+=i)while(q[j]%i==0){
			q[j]/=i; f[j]++;
		}
	}
	for(int i=2;i<=n;i++)if(f[i]<=2&&i!=F)s[i]=1;
	for(int i=1;i<=n;i++){
		while(S[dp[i]][i])dp[i]++;
		S[dp[i]]|=s<<i;
	}
	while(T--){
		int x=read(),y=read(),z=read();
		int s=y-x,t=z-y;
		ans^=dp[s]^dp[t];
	}
	if(ans)puts("Alice\nBob");
	else puts("Bob\nAlice");
}