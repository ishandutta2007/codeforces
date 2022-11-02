#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=300005,mod=998244353,K=42;
ll s[K][N],fac[N],ni[N],ans;
int n,m,vis[N],x[K/2],y[K/2],l[N],r[N],f[N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll c(int a,int b){
	return a>=b&&b>=0?fac[a]*ni[b]%mod*ni[a-b]%mod:0;
}
void dfs(int p,int dq,int zt,int L,int R){
	if(L>R)return;
	if(p>m){
		ans=(ans+zt*(s[dq][R]-s[dq][L-1]))%mod;
		return;
	}
	dfs(p+1,dq,zt,L,R);
	if(!vis[x[p]])dq++; vis[x[p]]++; 
	if(!vis[y[p]])dq++; vis[y[p]]++;
	dfs(p+1,dq,-zt,max(L,max(l[x[p]],l[y[p]])),min(R,min(r[x[p]],r[y[p]])));
	vis[x[p]]--; vis[y[p]]--;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); m=read();
	For(i,fac[0]=1,n)fac[i]=fac[i-1]*i%mod;
	ni[n]=ksm(fac[n],mod-2);
	Rep(i,n,1)ni[i-1]=ni[i]*i%mod;
	For(i,1,n){
		l[i]=read(); r[i]=read();
		f[l[i]]++; f[r[i]+1]--;
	}
	For(i,1,n)f[i]+=f[i-1];
	For(o,0,40){
		For(i,1,n)s[o][i]=(s[o][i-1]+c(f[i]-o,i-o))%mod;
	}
	For(i,1,m){
		x[i]=read(); y[i]=read();
	}
	dfs(1,0,1,1,n);
	cout<<(ans+mod)%mod<<endl;
}