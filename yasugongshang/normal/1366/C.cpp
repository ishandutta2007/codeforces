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
int a[35][35],b[35][35];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read(),m=read();
		For(i,1,n)For(j,1,m)a[i][j]=read();
		if(n>m){
			swap(n,m);
			For(i,1,n)For(j,1,m)b[i][j]=a[j][i];
			swap(a,b);
		}
		int ans=0;
		For(i,1,n){
			int A=0,B=0;
			For(j,1,i)A+=a[i-j+1][j];
			For(j,1,i)B+=a[n-i+j][m-j+1];
			if(n!=m||i!=n)ans+=min(A+B,i-A+i-B);
		}
		if(n!=m){
			int s=n+1,t=m-1;
			For(i,s,(s+t-1)/2){
				int A=0,B=0;
				For(j,1,n)A+=a[j][i-j+1];
				For(j,1,n)B+=a[j][t+s-i-j+1];
				ans+=min(A+B,n-A+n-B);
			}
		}
		cout<<ans<<endl;
	}
}