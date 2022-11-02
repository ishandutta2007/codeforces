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
const int N=200005;
int n,x,y;
int ans[N<<3];
const int NN=1<<19|2,mod=998244353,G=3;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
struct fft{
	int rev[NN],n,L;
	ll wn[NN],WN[NN];
	ull a[NN];
	void init(int N){
		n=1; L=0;
		while(n<N){
			n<<=1; L++;
		}
		ll w=ksm(G,(mod-1)/n);
		For(i,wn[0]=1,n-1){wn[i]=wn[i-1]*w%mod; rev[i]=rev[i>>1]>>1|((i&1)<<(L-1));}
	}
	void dft(poly &b){
		For(i,0,n-1)a[i]=b[rev[i]];
		for(int d=1,len=L-1;d<n;d<<=1,len--){
			For(j,0,d-1)WN[j]=wn[j<<len];
			for(int j=0;j<n;j+=d<<1){
				For(k,0,d-1){
					int t=WN[k]*a[j+k+d]%mod;
					a[j+k+d]=a[j+k]+mod-t;
					a[j+k]=a[j+k]+t;
				}
			}
		}
		For(i,0,n-1)b[i]=a[i]%mod;
	}
	void idft(poly &a){
		dft(a);
		reverse(a.begin()+1,a.end());
		ll zs=ksm(n,mod-2);
		For(i,0,n-1)a[i]=a[i]*zs%mod;
	}
}T;
void FFT(poly &a,poly &b){
	int cs=a.size()+b.size()-1;
	int len=1; while(len<cs)len<<=1;
	T.init(len);
	a.re(len); b.re(len);
	T.dft(a); T.dft(b);
	For(i,0,len-1)a[i]=a[i]*b[i]%mod;
	T.idft(a);
	a.re(cs);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); x=read(); y=read();
	poly s(x+1);
	For(i,0,n)s[read()]=1;
	poly t=s;
	reverse(t.begin(),t.end());
	FFT(s,t);
	For(i,1,x){
		ans[i+y]=s[i+x];
	}
	int q=read();
	while(q--){
		int l=read()/2,an=-1;
		for(int i=1;i*i<=l;i++)if(l%i==0){
			if(ans[l/i])an=max(an,l/i);
			if(ans[i])an=max(an,i);
		}
		wri(an<0?an:(an)*2);
	}
}