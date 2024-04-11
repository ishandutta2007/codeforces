#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=100005;
int a[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=1;
	while(T--){
		int n=read(),p=read();
		For(i,0,n-1)a[i]=read();
		sort(a,a+n); 
		int l=0,r=1e9;
		while(l<r){
			int mid=(l+r)>>1,dq=0,f=1; mid++;
			For(i,0,n-1){
				while(dq<n&&a[dq]<=mid+i)dq++;
				if(dq-i>=p)f=0;
			}
			if(f)l=mid; else r=mid-1;
		}
		int R=l;
		l=0; r=R+1;
		while(l<r){
			int mid=(l+r)>>1,dq=0,f=1;
			For(i,0,n-1){
				while(dq<n&&a[dq]<=mid+i)dq++;
				if(dq==i)f=0;
			}
			if(f)r=mid; else l=mid+1;
		}
		writeln(R-l+1);
		For(i,l,R)wri(i); 
	}
}
/*
kp+i=f(x+i)
i
*/