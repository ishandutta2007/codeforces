#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
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
const int K=10,N=9000005,mod=998244353;
ll inv[N],e[K],d[K],f[N];
int main(){
	int n=read(),k=read();
	n/=2;
	while(k--)d[read()]=1;
	for(int i=0;i<K;i++)if(d[i]){
		for(int j=i;j<K;j++)d[j-i]=d[j]; for(int j=K-i;j<K;j++)d[j]=0; break;
	}
	f[0]=1;
	for(int i=0;i<9;i++)e[i]=d[i+1]*(i+1);
	inv[1]=1; for(int i=2;i<=n*9;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=0;i<n*9;i++){
		int me=min(i,9); ll sum=0;
		for(int j=0;j<=me;j++){
			sum+=f[i-j]*e[j];
		}
		sum=sum%mod*n%mod; 
		for(int j=1;j<=me;j++){
			sum-=f[i-j+1]*d[j]*(i-j+1);
		}
		f[i+1]=(sum%mod+mod)%mod*inv[i+1]%mod;
		//if(f[i])cout<<i<<" "<<f[i]<<endl;
	}
	ll ans=0;
	//for(int i=0;i<=n*9;i++)cout<<f[i]<<endl;
	for(int i=0;i<=n*9;i++)ans=(ans+f[i]*f[i])%mod;
	cout<<ans<<endl;
}