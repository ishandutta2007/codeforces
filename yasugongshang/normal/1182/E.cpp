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
const int mod=1e9+6,mo=mod+1;
poly operator +(poly a,poly b){
	int n=b.size();
	if(a.size()<n)a.resize(n);
	For(i,0,n-1)a[i]=(a[i]+b[i])%mod;
	return a;
}
poly operator -(poly a,poly b){
	int n=b.size();
	if(a.size()<n)a.resize(n);
	For(i,0,n-1)a[i]=(a[i]-b[i]+mod)%mod;
	return a;
}
poly operator *(poly a,poly b){
	int as=a.size()-1,bs=b.size()-1,cs=as+bs; poly c(cs+1);
	For(i,0,as)For(j,0,bs){
		c[i+j]+=a[i]*b[j];
		c[i+j]%=mod;
	}
	For(i,0,cs)c[i]%=mod;
	return c;
}
struct matrix{
	ll a[5][5];
	ll* operator [](int x){
		return a[x];
	}
};
matrix operator *(matrix a,matrix b){
	matrix c; mem(c.a);
	For(i,0,4)For(j,0,4)For(k,0,4)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	return c;
}
matrix ks(matrix a,ll b){
	matrix ans; 
	mem(ans.a); For(i,0,4)ans[i][i]=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a;
		a=a*a;
	}
	return ans;
}
ll ksm(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mo;
		a=a*a%mo;
	}
	return ans;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	poly a(4),b(3);
	a[0]=1; a[1]=a[2]=a[3]=mod-1;
	b[0]=1; b[1]=mod-2; b[2]=1; 
	b=a*b;
	For(i,1,3)a[i]=mod-a[i];
	For(i,1,5)b[i]=mod-b[i];
	//For(i,0,5)cout<<b[i]<<endl;
	matrix t;
	ll n=read()-1;
	matrix zs; mem(zs.a);
	For(i,0,4){
		if(i)zs[i][i-1]=1; zs[i][4]=b[5-i];
	}
	zs=ks(zs,n);
	ll A[5];
	For(i,0,2)A[i]=read();
	ll C=read();
	A[3]=A[0]*A[1]%mo*A[2]%mo*C%mo*C%mo;
	A[4]=A[1]*A[2]%mo*A[3]%mo*C%mo*C%mo*C%mo*C%mo;
	ll ans=1;
	For(i,0,4){
		//cout<<zs[i][0]<<endl;
		ans=ans*ksm(A[i],zs[i][0])%mo;
	}
	cout<<ans<<endl;
}