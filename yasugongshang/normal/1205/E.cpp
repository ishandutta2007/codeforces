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
const int N=100005,mod=1e9+7;
ll ans[N],sum[N];
int phi[N],pr[N/10];
bitset<N> heshu;
ll ksm(ll a,int b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int n=read(),k=read();
	phi[1]=1;
	For(i,2,n){
		if(!heshu[i]){
			phi[i]=i-1; pr[++*pr]=i;
		}
		for(int j=1;j<=*pr&&i*pr[j]<=n;j++){
			int k=i*pr[j];
			heshu[k]=1;
			if(i%pr[j]==0){phi[k]=phi[i]*pr[j]; break;}
			else phi[k]=phi[i]*(pr[j]-1);
		}
	}
	For(i,2,n)sum[i]=sum[i-1]+phi[i];
	For(i,0,n-1)ans[i]=n-i-1;
	For(d,1,n-1){
		int x=(n+d-1)/d;
		ans[d]+=sum[x];
		ans[x*d-n]-=phi[x];
	}
	ll tot=0,dq=1;
	For(i,0,n-1){
		tot=(tot+ans[i]%mod*dq)%mod; dq=dq*k%mod;
	}
	cout<<tot*ksm(k,mod-1-n)%mod<<endl;
}