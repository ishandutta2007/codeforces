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
	ull ans=0;
	For(i,0,5)ans=ans<<15^rand();
	return ans;
}
const int N=100005;
PI p[N],q[N];
int A[N],B[N],C[N],D[N];
ull h[N],F[N],G[N];
void solve(int l[N],int r[N],ull a[N],int n){
	For(i,1,n){
		p[i]=mp(l[i],i); q[i]=mp(r[i],i);
	}
	sort(p+1,p+n+1);
	sort(q+1,q+n+1);
	int dq=n; ull sum=0;
	Rep(i,n,1){
		while(dq&&p[dq].fi>q[i].fi){
			sum^=h[p[dq].se]; dq--;
		}
		a[q[i].se]=sum;
	}
	dq=1; sum=0;
	For(i,1,n){
		while(dq<=n&&q[dq].fi<p[i].fi){
			sum^=h[q[dq].se]; dq++;
		}
		a[p[i].se]^=sum;
	}
}
int main(){
	int n=read();
	For(i,1,n){
		A[i]=read(); B[i]=read(); C[i]=read(); D[i]=read();
		h[i]=rnd();
	}
	solve(A,B,F,n);
	solve(C,D,G,n);
	For(i,1,n)if(F[i]!=G[i]){
		puts("NO"); return 0;
	}
	puts("YES");
}