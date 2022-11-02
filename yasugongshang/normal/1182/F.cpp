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
const int B=32000;
ll a,b,p,q,qq,mn,ans;
void solve(int i){
	ll t=abs(i*p%qq-q);
	if(t<mn||t==mn&&i<ans){
		mn=t; ans=i;
	}
}
PI to[B];
ll xqz(ll a,ll b){
	return a>0||a%b?a/b:a/b-1;
}
ll solve(ll a,ll b,ll c,ll n){
	//ll ans=0; For(i,0,n-1)ans+=(a*i+b)/c; return ans;
	if(n<=0)return 0;
	if(!a)return b/c*n;
	if(a>=c||b>=c){
		return solve(a%c,b%c,c,n)+(b/c)*n+n*(n-1)/2*(a/c);
	}else{
		ll m=(a*(n-1)+b)/c;
		return (n-1)*m-solve(c,c-b-1,a,m);
	}
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1; y=0; return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
void bao(ll de){
	ll x,y;
	exgcd(p,qq,x,y);
	ll t=__gcd(p,qq);
	if(de%t)return;
	x*=de/t; y*=de/t;
	ll Q=qq/t;
	x=(x%Q+Q)%Q;
	if(a/Q*Q+x>=a)solve(a/Q*Q+x);
	else solve(a/Q*Q+Q+x);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		a=read(),b=read()+1,p=read()*2,q=read(),qq=q<<1;
		mn=2e9;
		int l=0,r=q;
		while(l<r){
			int mid=(l+r)>>1; 
			int L=q-mid,R=q+mid;
			if((solve(p,qq-L,qq,b)-solve(p,qq-L,qq,a))-
			(solve(p,qq-R-1,qq,b)-solve(p,qq-R-1,qq,a)))r=mid; else l=mid+1;
		}
		bao(q-l); bao(q+l);
		cout<<ans<<endl;
	}
}
/*
2px+yq=L
1
53759 617353 370492 361189
*/